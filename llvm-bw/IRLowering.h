#pragma once

#include "TriggerTypes/DecoratedTrigger.h"
#include "IRReader.h"

#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/Instruction.h>

#include <vector>
#include <map>
#include <cstdint>
#include <string>

namespace llvmbw {
  class IRLowering {
  private:
    const IRReader& ir;

    std::vector<DecoratedTrigger> triggers;
    std::map<std::string, size_t> trigger_symbols_map;

  public:
    IRLowering(const IRReader _ir) : ir(_ir) {}

    bool lower_all();

    bool lower_globals();
    bool lower_global(const llvm::GlobalVariable& g);

    bool lower_functions();
    bool lower_function(const llvm::Function& f);
    bool lower_function_block(const llvm::BasicBlock& block);
    bool lower_instruction(const llvm::Instruction& inst);

    bool checkSupportedType(const llvm::Type* t);

  };
}
