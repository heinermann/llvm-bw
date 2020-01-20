#pragma once
#include "TrigInst.h"
#include "Block.h"

#include <vector>
#include <memory>
#include <optional>
#include <unordered_map>
#include <string>

namespace llvmbw {
  class Function : public TrigInst {
  private:
    std::vector<std::shared_ptr<Block>> blocks;
    std::unordered_map<std::string, std::shared_ptr<Block>> local_symbol_map;

  public:
    Function(const std::string& id) : TrigInst(TrigInst::Type::Function, id)
    {}

    virtual ~Function() override {}

    virtual bool optimizationPass() override;
    virtual std::ostream& writeDot(std::ostream& os) override;
    virtual std::ostream& writeTxt(std::ostream& os, int tab = 0) override;

    void add_block(std::shared_ptr<Block> block);
  };
}
