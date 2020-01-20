#pragma once

#include "TriggerIR/Program.h"
#include "TriggerIR/Function.h"
#include "TriggerIR/Block.h"
#include "TriggerIR/TrigInst.h"
#include "IRReader.h"

#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/Instruction.h>

#include <cstdint>
#include <memory>

namespace llvmbw {
  class IRLowering {
  private:
    const IRReader& ir;

  public:
    IRLowering(const IRReader _ir) : ir(_ir) {}

    std::shared_ptr<Program> lower_all();

    void lower_globals(Program& program);
    void lower_global(const llvm::GlobalVariable& g);

    void lower_functions(Program& program);
    std::shared_ptr<Function> lower_function(const llvm::Function& f);
    std::shared_ptr<Block> lower_function_block(const llvm::BasicBlock& block);
    std::shared_ptr<TrigInst> lower_instruction(const llvm::Instruction& inst);
    std::shared_ptr<TrigInst> lower_value(const llvm::Value* value);

    bool checkSupportedType(const llvm::Type* t);

  };
}
