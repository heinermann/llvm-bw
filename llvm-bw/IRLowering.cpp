#include "IRLowering.h"

#include <llvm/Support/raw_ostream.h>
#include <llvm/IR/Instructions.h>

using namespace llvmbw;

bool IRLowering::lower_all()
{
  return lower_globals()
    & lower_functions();
}

bool IRLowering::lower_globals()
{
  bool success = true;
  for (const llvm::GlobalVariable& g : ir.module->globals()) {
    success &= lower_global(g);
  }
  return success;
}

bool IRLowering::lower_global(const llvm::GlobalVariable& g)
{
  std::cerr << "ERROR: [" << g.getName().str() << "] Globals are unsupported" << std::endl;
  return false;
}


bool IRLowering::lower_functions()
{
  bool success = true;
  for (const llvm::Function& f : ir.module->functions()) {
    success &= lower_function(f);
  }
  return success;
}

bool IRLowering::lower_function(const llvm::Function& f)
{
  if (f.doesNotReturn()) {
    std::cerr << "ERROR: [" << f.getName().str() << "] noreturn is unsupported" << std::endl;
    return false;
  }
  if (f.getFunctionType()->getNumParams() > 0) {
    std::cerr << "ERROR: [" << f.getName().str() << "] function params is unsupported" << std::endl;
    return false;
  }
  if (!checkSupportedType(f.getFunctionType()->getReturnType())) {
    std::cerr << "ERROR: [" << f.getName().str() << "] return type is unsupported" << std::endl;
    return false;
  }

  bool success = true;
  for (const llvm::BasicBlock& block : f) {
    success &= lower_function_block(block);
  }
  return success;
}

bool IRLowering::lower_function_block(const llvm::BasicBlock& block)
{
  bool success = true;
  for (const llvm::Instruction& inst : block) {
    success &= lower_instruction(inst);
  }
  return false;
}

bool IRLowering::lower_instruction(const llvm::Instruction& inst)
{
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

    if (store_inst.isVolatile()) {
      std::cerr << "ERROR: [StoreInst] volatile is unsupported" << std::endl;
      return false;
    }
    if (!store_inst.isUnordered()) {
      std::cerr << "ERROR: [StoreInst] ordering is unsupported" << std::endl;
      return false;
    }
    if (store_inst.getAlignment() % 4 != 0) {
      std::cerr << "ERROR: [StoreInst] alignment to non-32-bit boundary is unsupported" << std::endl;
      return false;
    }

    const llvm::Value* value = store_inst.getValueOperand();
    const llvm::Value* pointer = store_inst.getPointerOperand();

    if (!llvm::Constant::classof(value)) {
      std::cerr << "ERROR: [Store] non-const value operand is unsupported" << std::endl;
      return false;
    }
    if (value->getValueID() != llvm::Value::ConstantIntVal) {
      std::cerr << "ERROR: [Store] non-int value operand is unsupported" << std::endl;
      return false;
    }
    if (!llvm::Constant::classof(pointer)) {
      std::cerr << "ERROR: [Store] non-const pointer operand is unsupported" << std::endl;
      return false;
    }
    if (pointer->getValueID() != llvm::Value::ConstantExprVal) {
      std::cerr << "ERROR: [Store] non-const-expr pointer operand is unsupported" << std::endl;
      return false;
    }

    // TODO: Eval
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

    if (!llvm::Constant::classof(value)) {
      std::cerr << "ERROR: [IntToPtr] non-const value operand is unsupported" << std::endl;
      return false;
    }
    if (value->getValueID() != llvm::Value::ConstantIntVal) {
      std::cerr << "ERROR: [IntToPtr] non-int value operand is unsupported" << std::endl;
      return false;
    }

    // TODO: Eval
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
  std::cerr << "ERROR: [" << inst.getName().str() << "] instruction is unsupported" << std::endl;
  return false;
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
  {
    if (t->getIntegerBitWidth() == 0) {
      std::cerr << "ERROR: IntegerType can't have bit width of 0" << std::endl;
      return false;
    }
    if (t->getIntegerBitWidth() > 32) {
      std::cerr << "ERROR: IntegerType bit widths of > 32-bit are unsupported" << std::endl;
      return false;
    }
    return true;
  }
    break;
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
  
  std::cerr << "ERROR: Type is unsupported - " << type_str << std::endl;
  return false;
}

