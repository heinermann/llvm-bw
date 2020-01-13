#include "IRReader.h"

#include <llvm/Support/SourceMgr.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/ValueSymbolTable.h>

#include <iostream>

using namespace llvmbw;

IRReader::IRReader(const std::string& filename) {
  this->loadFile(filename);
}

bool IRReader::loadFile(const std::string& filename) {
  llvm::SMDiagnostic err;

  this->module = llvm::parseIRFile(filename, err, context);
  if (!this->module) {
    // TODO fix whatever this was...
    std::string output_str;
    llvm::raw_string_ostream out(output_str);
    err.print("llvm-bw", out);

    std::cerr << output_str << std::endl;
    std::cerr << err.getMessage().str() << std::endl;
    return false;
  }

  std::cout << "Loaded.\n";
  std::cout << "  Module Name: " << module->getName().str() << "\n";
  std::cout << "  Data layout: " << module->getDataLayoutStr() << "\n";
  std::cout << std::endl;

  return true;
}

void IRReader::debugPrintAll() const {
  debugPrintSymbols();
  debugPrintGlobals();
  debugPrintFunctions();
  debugPrintAliases();
  debugPrintIFuncs();
  debugPrintMetadata();
}

void IRReader::debugPrintSymbols() const {
  std::cout << "Symbols:\n";
  for (const llvm::ValueName& symbol : module->getValueSymbolTable()) {
    std::cout << "  " << symbol.getKey().str() << "\n";
  }
  std::cout << std::endl;
}

void IRReader::debugPrintGlobals() const {
  std::cout << "Global Variables:\n";
  for (llvm::GlobalVariable& g : module->globals()) {
    std::string type_str;
    llvm::raw_string_ostream rso(type_str);
    g.print(rso);

    

    std::cout << "  " << type_str << "\n";
    std::cout << g.getName().str() << std::endl;
  }
  std::cout << std::endl;
}

bool processOp(const llvm::Instruction& inst, int indent = 0);
void processType(const llvm::Type* t, int indent = 0);
void processValue(const llvm::Value* value, int indent = 0);

void processType(const llvm::Type* t, int indent) {
  switch (t->getTypeID()) {
  case llvm::Type::VoidTyID:
    std::cout << "void ";
    break;
  case llvm::Type::HalfTyID:
    std::cout << "16-bit fp ";
    break;
  case llvm::Type::FloatTyID:
    std::cout << "32-bit fp ";
    break;
  case llvm::Type::DoubleTyID:
    std::cout << "64-bit fp ";
    break;
  case llvm::Type::X86_FP80TyID:
    std::cout << "80-bit fp ";
    break;
  case llvm::Type::FP128TyID:
    std::cout << "128-bit fp ";
    break;
  case llvm::Type::PPC_FP128TyID:
    std::cout << "128-bit fp (ppc) ";
    break;
  case llvm::Type::LabelTyID:
    std::cout << "label ";
    break;
  case llvm::Type::MetadataTyID:
    std::cout << "metadata ";
    break;
  case llvm::Type::X86_MMXTyID:
    std::cout << "mmx vector ";
    break;
  case llvm::Type::TokenTyID:
    std::cout << "token ";
    break;
  case llvm::Type::IntegerTyID:
    std::cout << "integer ";
    break;
  case llvm::Type::FunctionTyID:
    std::cout << "function ";
    break;
  case llvm::Type::StructTyID:
    std::cout << "struct ";
    break;
  case llvm::Type::ArrayTyID:
    std::cout << "array ";
    break;
  case llvm::Type::PointerTyID:
    std::cout << "pointer ";
    break;
  case llvm::Type::VectorTyID:
    std::cout << "vector ";
    break;
  }
}

void processValue(const llvm::Value* value, int indent) {
  switch (value->getValueID()) {
  case llvm::Value::FunctionVal:
    std::cout << std::string(indent, ' ') << "FunctionVal";
    break;
  case llvm::Value::GlobalAliasVal:
    std::cout << std::string(indent, ' ') << "GlobalAliasVal";
    break;
  case llvm::Value::GlobalIFuncVal:
    std::cout << std::string(indent, ' ') << "GlobalIFuncVal";
    break;
  case llvm::Value::GlobalVariableVal:
    std::cout << std::string(indent, ' ') << "GlobalVariableVal";
    break;
  case llvm::Value::BlockAddressVal:
    std::cout << std::string(indent, ' ') << "BlockAddressVal";
    break;
  case llvm::Value::ConstantExprVal:
  {
    const llvm::ConstantExpr* const_expr = static_cast<const llvm::ConstantExpr*>(value);
    std::cout << std::string(indent, ' ') << "ConstantExprVal("
      << "opcode=" << const_expr->getOpcodeName()
      << ")" << std::endl;
    const llvm::Instruction* const_expr_inst = const_expr->getAsInstruction();
    processOp(*const_expr_inst, indent + 2);
  }
    break;
  case llvm::Value::ConstantArrayVal:
    std::cout << std::string(indent, ' ') << "ConstantArrayVal";
    break;
  case llvm::Value::ConstantStructVal:
    std::cout << std::string(indent, ' ') << "ConstantStructVal";
    break;
  case llvm::Value::ConstantVectorVal:
    std::cout << std::string(indent, ' ') << "ConstantVectorVal";
    break;
  case llvm::Value::UndefValueVal:
    std::cout << std::string(indent, ' ') << "UndefValueVal";
    break;
  case llvm::Value::ConstantAggregateZeroVal:
    std::cout << std::string(indent, ' ') << "ConstantAggregateZeroVal";
    break;
  case llvm::Value::ConstantDataArrayVal:
    std::cout << std::string(indent, ' ') << "ConstantDataArrayVal";
    break;
  case llvm::Value::ConstantDataVectorVal:
    std::cout << std::string(indent, ' ') << "ConstantDataVectorVal";
    break;
  case llvm::Value::ConstantIntVal:
  {
    const llvm::ConstantInt* const_int = static_cast<const llvm::ConstantInt*>(value);

    std::cout << std::string(indent, ' ') << "ConstantIntVal("
      << "bitWidth=" << const_int->getBitWidth()
      << ", value=" << const_int->getZExtValue()
      << ")" << std::endl;
  }
    break;
  case llvm::Value::ConstantFPVal:
    std::cout << std::string(indent, ' ') << "ConstantFPVal";
    break;
  case llvm::Value::ConstantPointerNullVal:
    std::cout << std::string(indent, ' ') << "ConstantPointerNullVal";
    break;
  case llvm::Value::ConstantTokenNoneVal:
    std::cout << std::string(indent, ' ') << "ConstantTokenNoneVal";
    break;
  case llvm::Value::ArgumentVal:
    std::cout << std::string(indent, ' ') << "ArgumentVal";
    break;
  case llvm::Value::BasicBlockVal:
    std::cout << std::string(indent, ' ') << "BasicBlockVal";
    break;
  case llvm::Value::MetadataAsValueVal:
    std::cout << std::string(indent, ' ') << "MetadataAsValueVal";
    break;
  case llvm::Value::InlineAsmVal:
    std::cout << std::string(indent, ' ') << "InlineAsmVal";
    break;
  case llvm::Value::MemoryUseVal:
    std::cout << std::string(indent, ' ') << "MemoryUseVal";
    break;
  case llvm::Value::MemoryDefVal:
    std::cout << std::string(indent, ' ') << "MemoryDefVal";
    break;
  case llvm::Value::MemoryPhiVal:
    std::cout << std::string(indent, ' ') << "MemoryPhiVal";
    break;
  case llvm::Value::InstructionVal:
    std::cout << std::string(indent, ' ') << "InstructionVal";
    break;
  default:
    break;
  }
}

bool processOp(const llvm::Instruction& inst, int indent) {
  switch (inst.getOpcode()) {
  case llvm::Instruction::Ret:
    break;
  case llvm::Instruction::Br:
    break;
  case llvm::Instruction::Switch:
    break;
  case llvm::Instruction::IndirectBr:
    break;
  case llvm::Instruction::Invoke:
    break;
  case llvm::Instruction::Resume:
    break;
  case llvm::Instruction::Unreachable:
    break;
  case llvm::Instruction::CleanupRet:
    break;
  case llvm::Instruction::CatchSwitch:
    break;
  case llvm::Instruction::CallBr:
    break;
  case llvm::Instruction::Add:
    break;
  case llvm::Instruction::FAdd:
    break;
  case llvm::Instruction::Sub:
    break;
  case llvm::Instruction::FSub:
    break;
  case llvm::Instruction::Mul:
    break;
  case llvm::Instruction::FMul:
    break;
  case llvm::Instruction::UDiv:
    break;
  case llvm::Instruction::SDiv:
    break;
  case llvm::Instruction::FDiv:
    break;
  case llvm::Instruction::URem:
    break;
  case llvm::Instruction::SRem:
    break;
  case llvm::Instruction::FRem:
    break;
  case llvm::Instruction::Shl:
    break;
  case llvm::Instruction::LShr:
    break;
  case llvm::Instruction::AShr:
    break;
  case llvm::Instruction::And:
    break;
  case llvm::Instruction::Or:
    break;
  case llvm::Instruction::Xor:
    break;
  case llvm::Instruction::Alloca:
    break;
  case llvm::Instruction::Load:
    break;
  case llvm::Instruction::Store:
  {
    const llvm::StoreInst& store_inst = static_cast<const llvm::StoreInst&>(inst);
    std::cout << std::string(indent, ' ') << "Store: Align = " << store_inst.getAlignment()
      << "; Volatile = " << store_inst.isVolatile()
      << "; Atomic = " << store_inst.isAtomic()
      << "; Ordering = " << llvm::toIRString(store_inst.getOrdering())
      << std::endl;

    const llvm::Value* value = store_inst.getValueOperand();
    std::cout << std::string(indent, ' ') << "Value:\n";
    processValue(value, indent + 2);

    const llvm::Value* pointer = store_inst.getPointerOperand();
    std::cout << std::string(indent, ' ') << "Pointer:\n";
    processValue(pointer, indent + 2);
  }
    break;
  case llvm::Instruction::GetElementPtr:
    break;
  case llvm::Instruction::Fence:
    break;
  case llvm::Instruction::AtomicCmpXchg:
    break;
  case llvm::Instruction::AtomicRMW:
    break;
  case llvm::Instruction::Trunc:
    break;
  case llvm::Instruction::ZExt:
    break;
  case llvm::Instruction::SExt:
    break;
  case llvm::Instruction::FPToUI:
    break;
  case llvm::Instruction::FPToSI:
    break;
  case llvm::Instruction::UIToFP:
    break;
  case llvm::Instruction::SIToFP:
    break;
  case llvm::Instruction::FPTrunc:
    break;
  case llvm::Instruction::FPExt:
    break;
  case llvm::Instruction::PtrToInt:
    break;
  case llvm::Instruction::IntToPtr:
  {
    const llvm::IntToPtrInst& int_to_ptr_inst = static_cast<const llvm::IntToPtrInst&>(inst);
    std::cout << std::string(indent, ' ')
      << "Operands=" << int_to_ptr_inst.getNumOperands()
      << std::endl;
    processValue(int_to_ptr_inst.getOperand(0), indent + 2);
  }
    break;
  case llvm::Instruction::BitCast:
    break;
  case llvm::Instruction::AddrSpaceCast:
    break;
  case llvm::Instruction::CleanupPad:
    break;
  case llvm::Instruction::CatchPad:
    break;
  case llvm::Instruction::ICmp:
    break;
  case llvm::Instruction::FCmp:
    break;
  case llvm::Instruction::PHI:
    break;
  case llvm::Instruction::Call:
    break;
  case llvm::Instruction::Select:
    break;
  case llvm::Instruction::UserOp1:
    break;
  case llvm::Instruction::UserOp2:
    break;
  case llvm::Instruction::VAArg:
    break;
  case llvm::Instruction::ExtractElement:
    break;
  case llvm::Instruction::InsertElement:
    break;
  case llvm::Instruction::ShuffleVector:
    break;
  case llvm::Instruction::ExtractValue:
    break;
  case llvm::Instruction::InsertValue:
    break;
  case llvm::Instruction::LandingPad:
    break;
  case llvm::Instruction::Freeze:
    break;
  case llvm::Instruction::FNeg:
    break;
  default:
    break;
  }
  std::cerr << std::string(indent, ' ')
    << "\nUnsupported opcode: "
    << inst.getOpcodeName()
    << std::endl;
  return false;
}

void IRReader::debugPrintFunctions() const {
  std::cout << "Functions:\n";
  for (llvm::Function& f : module->functions()) {
    std::string type_str;
    llvm::raw_string_ostream rso(type_str);
    f.print(rso);

    std::cout << "  " << type_str << "\n";
  }
  std::cout << std::endl;

  std::cout << "MAIN\n";
  llvm::Function* f_main = module->getFunction("main");
  for (llvm::BasicBlock& b : *f_main) {
    std::cout << "  BLOCK:\n";
    for (const llvm::Instruction& in : b) {
      std::cout << in.getOpcodeName() << " - " << in.getNumOperands() << " operands\n";
      processOp(in, 2);
    }
  }
}



void IRReader::debugPrintAliases() const {
  std::cout << "Aliases:\n";
  for (llvm::GlobalAlias& f : module->aliases()) {
    std::string type_str;
    llvm::raw_string_ostream rso(type_str);
    f.print(rso);

    std::cout << "  " << type_str << "\n";
  }
  std::cout << std::endl;
}
void IRReader::debugPrintIFuncs() const {
  std::cout << "IFuncs:\n";
  for (llvm::GlobalIFunc& f : module->ifuncs()) {
    std::string type_str;
    llvm::raw_string_ostream rso(type_str);
    f.print(rso);

    std::cout << "  " << type_str << "\n";
  }
  std::cout << std::endl;
}
void IRReader::debugPrintMetadata() const {
  std::cout << "Named Metadata:\n";
  for (llvm::NamedMDNode& f : module->named_metadata()) {
    std::string type_str;
    llvm::raw_string_ostream rso(type_str);
    f.print(rso);

    std::cout << "  " << type_str << "\n";
  }
  std::cout << std::endl;
}
