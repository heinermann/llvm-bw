#pragma once
#include "TrigInst.h"

#include <vector>
#include <memory>

namespace llvmbw {
  class Block : public TrigInst {
  private:
    std::vector<std::shared_ptr<TrigInst>> instructions;

  public:
    Block(const std::string& id) : TrigInst(TrigInst::Type::Block, id)
    {}

    virtual ~Block() override {}

    virtual bool optimizationPass() override;
    virtual std::ostream& writeDot(std::ostream& os) override;
    virtual std::ostream& writeTxt(std::ostream& os, int tab = 0) override;
  };
}
