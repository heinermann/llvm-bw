#include "IRLowering.h"

#include "Exceptions/UnsupportedException.h"
#include "TriggerIR/Constant.h"
#include "TriggerIR/Ptr.h"
#include "TriggerIR/Assign.h"
#include "TriggerIR/Retn.h"

#include <llvm/Support/raw_ostream.h>
#include <llvm/IR/Instructions.h>

#include <iostream>

using namespace llvmbw;

std::shared_ptr<Program> IRLowering::lower_all()
{
  std::shared_ptr<Program> program = std::make_shared<Program>();
  try {

    lower_globals(*program);
    lower_functions(*program);
  }
  catch (std::exception & e) {
    std::cerr << "[ERROR] " << e.what() << std::endl;
  }
  return program;
}

void IRLowering::lower_globals(Program& program)
{
  for (const llvm::GlobalVariable& g : ir.module->globals()) {
    try {
      lower_global(g);
    }
    catch (std::exception & e) {
      std::cerr << "[ERROR] " << e.what() << std::endl;
    }
  }
}

void IRLowering::lower_global(const llvm::GlobalVariable& g)
{
  throw NamedUnsupportedException(g.getName().str(), "Globals");
}


void IRLowering::lower_functions(Program& program)
{
  for (const llvm::Function& f : ir.module->functions()) {
    try {
      program.add_function(lower_function(f));
    }
    catch (std::exception & e) {
      std::cerr << "[ERROR] " << e.what() << std::endl;
    }
  }
}

std::shared_ptr<Function> IRLowering::lower_function(const llvm::Function& f)
{
  if (f.doesNotReturn()) throw NamedUnsupportedException(f.getName().str(), "noreturn");
  if (f.getFunctionType()->getNumParams() > 0) throw NamedUnsupportedException(f.getName().str(), "function params");
  if (!checkSupportedType(f.getFunctionType()->getReturnType())) throw NamedUnsupportedException(f.getName().str(), "return types");

  std::shared_ptr<Function> result_function = std::make_shared<Function>(f.getName().str());
  for (const llvm::BasicBlock& block : f) {
    result_function->add_block(lower_function_block(block));
  }
  return result_function;
}

std::shared_ptr<Block> IRLowering::lower_function_block(const llvm::BasicBlock& block)
{
  std::shared_ptr<Block> result = std::make_shared<Block>(block.getName().str());
  for (const llvm::Instruction& inst : block) {
    result->add_instruction(lower_instruction(inst));
  }
  return result;
}


std::shared_ptr<TrigInst> IRLowering::lower_instruction(const llvm::Instruction& inst)
{
  switch (inst.getOpcode()) {
  case llvm::Instruction::Ret:
  {
    const llvm::ReturnInst& retn_inst = static_cast<const llvm::ReturnInst&>(inst);

    if (retn_inst.getReturnValue() == nullptr) {
      return std::make_shared<Retn>();
    }
    else {
      return std::make_shared<Retn>(lower_value(retn_inst.getReturnValue()));
    }
  }
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

    if (store_inst.isVolatile()) throw NamedUnsupportedException("StoreInst", "volatile");
    if (!store_inst.isUnordered()) throw NamedUnsupportedException("StoreInst", "ordering");
    if (store_inst.getAlignment() % 4 != 0) throw NamedUnsupportedException("Store", "allignment to non-32-bit boundary");

    const llvm::Value* value = store_inst.getValueOperand();
    const llvm::Value* pointer = store_inst.getPointerOperand();

    if (!llvm::Constant::classof(value)) throw NamedUnsupportedException("StoreInst", "non-const value operand");
    if (value->getValueID() != llvm::Value::ConstantIntVal) throw NamedUnsupportedException("StoreInst", "non-int value operand");
    if (!llvm::Constant::classof(pointer)) throw NamedUnsupportedException("StoreInst", "non-const pointer operand");
    if (pointer->getValueID() != llvm::Value::ConstantExprVal) throw NamedUnsupportedException("StoreInst", "non-const-expr pointer operand"); 

    if (value->getValueID() == llvm::Value::ConstantIntVal && pointer->getValueID() == llvm::Value::ConstantExprVal) {

      return std::make_shared<Assign>(lower_value(pointer), lower_value(value));
    }
    else {
      throw NamedUnsupportedException("StoreInst", "");
    }
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
    const llvm::Value* value = int_to_ptr_inst.getOperand(0);

    if (!llvm::Constant::classof(value)) throw NamedUnsupportedException("IntToPtr", "non-const value operand"); 
    if (value->getValueID() != llvm::Value::ConstantIntVal) throw NamedUnsupportedException("IntToPtr", "non-int value operand"); 

    // TODO: Eval
    return std::make_shared<Ptr>(lower_value(value));
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
  throw NamedUnsupportedException(inst.getOpcodeName(), "instruction");
}

bool IRLowering::checkSupportedType(const llvm::Type* t) {
  switch (t->getTypeID()) {
  case llvm::Type::VoidTyID:
    break;
  case llvm::Type::HalfTyID:
    break;
  case llvm::Type::FloatTyID:
    break;
  case llvm::Type::DoubleTyID:
    break;
  case llvm::Type::X86_FP80TyID:
    break;
  case llvm::Type::FP128TyID:
    break;
  case llvm::Type::PPC_FP128TyID:
    break;
  case llvm::Type::LabelTyID:
    break;
  case llvm::Type::MetadataTyID:
    break;
  case llvm::Type::X86_MMXTyID:
    break;
  case llvm::Type::TokenTyID:
    break;
  case llvm::Type::IntegerTyID:
    if (t->getIntegerBitWidth() == 0) throw NamedUnsupportedException("IntegerType", "bit-width of 0");
    if (t->getIntegerBitWidth() > 32) throw NamedUnsupportedException("IntegerType", "bit widths of > 32-bit");
    return true;
  case llvm::Type::FunctionTyID:
    break;
  case llvm::Type::StructTyID:
    break;
  case llvm::Type::ArrayTyID:
    break;
  case llvm::Type::PointerTyID:
    break;
  case llvm::Type::VectorTyID:
    break;
  }

  std::string type_str;
  llvm::raw_string_ostream rso(type_str);
  t->print(rso);
  
  throw NamedUnsupportedException(type_str, "type");
}

std::shared_ptr<TrigInst> IRLowering::lower_value(const llvm::Value* value) {
  switch (value->getValueID()) {
  case llvm::Value::FunctionVal:
    throw NamedUnsupportedException("FunctionVal", "type");
  case llvm::Value::GlobalAliasVal:
    throw NamedUnsupportedException("GlobalAliasVal", "type");
  case llvm::Value::GlobalIFuncVal:
    throw NamedUnsupportedException("GlobalIFuncVal", "type");
  case llvm::Value::GlobalVariableVal:
    throw NamedUnsupportedException("GlobalVariableVal", "type");
  case llvm::Value::BlockAddressVal:
    throw NamedUnsupportedException("BlockAddressVal", "type");
  case llvm::Value::ConstantExprVal:
  {
    const llvm::ConstantExpr* const_expr = static_cast<const llvm::ConstantExpr*>(value);
    const llvm::Instruction* const_expr_inst = const_expr->getAsInstruction();
    return this->lower_instruction(*const_expr_inst);
  }
  break;
  case llvm::Value::ConstantArrayVal:
    throw NamedUnsupportedException("ConstantArrayVal", "type");
  case llvm::Value::ConstantStructVal:
    throw NamedUnsupportedException("ConstantStructVal", "type");
  case llvm::Value::ConstantVectorVal:
    throw NamedUnsupportedException("ConstantVectorVal", "type");
  case llvm::Value::UndefValueVal:
    throw NamedUnsupportedException("UndefValueVal", "type");
  case llvm::Value::ConstantAggregateZeroVal:
    throw NamedUnsupportedException("ConstantAggregateZeroVal", "type");
  case llvm::Value::ConstantDataArrayVal:
    throw NamedUnsupportedException("ConstantDataArrayVal", "type");
  case llvm::Value::ConstantDataVectorVal:
    throw NamedUnsupportedException("ConstantDataVectorVal", "type");
  case llvm::Value::ConstantIntVal:
  {
    const llvm::ConstantInt* const_int = static_cast<const llvm::ConstantInt*>(value);
    if (const_int->getBitWidth() > 32) throw NamedUnsupportedException("ConstantIntVal", "> 32 bit constants");
    if (const_int->getBitWidth() == 0) throw NamedUnsupportedException("ConstantIntVal", "0 bit constants");

    return std::make_shared<Constant>(static_cast<uint32_t>(const_int->getZExtValue()), (1ULL << const_int->getBitWidth()) - 1);
  }
  break;
  case llvm::Value::ConstantFPVal:
    throw NamedUnsupportedException("ConstantFPVal", "type");
  case llvm::Value::ConstantPointerNullVal:
    throw NamedUnsupportedException("ConstantPointerNullVal", "type");
  case llvm::Value::ConstantTokenNoneVal:
    throw NamedUnsupportedException("ConstantTokenNoneVal", "type");
  case llvm::Value::ArgumentVal:
    throw NamedUnsupportedException("ArgumentVal", "type");
  case llvm::Value::BasicBlockVal:
    throw NamedUnsupportedException("BasicBlockVal", "type");
  case llvm::Value::MetadataAsValueVal:
    throw NamedUnsupportedException("MetadataAsValueVal", "type");
  case llvm::Value::InlineAsmVal:
    throw NamedUnsupportedException("InlineAsmVal", "type");
  case llvm::Value::MemoryUseVal:
    throw NamedUnsupportedException("MemoryUseVal", "type");
  case llvm::Value::MemoryDefVal:
    throw NamedUnsupportedException("MemoryDefVal", "type");
  case llvm::Value::MemoryPhiVal:
    throw NamedUnsupportedException("MemoryPhiVal", "type");
  case llvm::Value::InstructionVal:
    throw NamedUnsupportedException("InstructionVal", "type");
  default:
    break;
  }
}
