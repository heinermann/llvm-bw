#pragma once
#include "TrigInst.h"

#include <vector>
#include <memory>

namespace llvmbw {
  class Assign : public TrigInst {
  private:
    std::shared_ptr<TrigInst> lhs;
    std::shared_ptr<TrigInst> rhs;

  public:
    Assign(std::shared_ptr<TrigInst> _lhs, std::shared_ptr<TrigInst> _rhs)
      : TrigInst(TrigInst::Type::Assign)
      , lhs(_lhs)
      , rhs(_rhs)
    {}

    virtual ~Assign() override {}

    virtual bool optimizationPass() override;
    virtual std::ostream& writeDot(std::ostream& os) override;
    virtual std::ostream& writeTxt(std::ostream& os, int tab = 0) override;
  };
}
