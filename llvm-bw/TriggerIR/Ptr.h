#pragma once
#include "TrigInst.h"

#include <memory>

namespace llvmbw {
  class Ptr : public TrigInst {
  private:
    std::shared_ptr<TrigInst> value;

  public:
    Ptr(std::shared_ptr<TrigInst> _value)
      : TrigInst(TrigInst::Type::Ptr)
      , value(_value)
    {}

    virtual ~Ptr() override {}

    virtual bool optimizationPass() override;
    virtual std::ostream& writeDot(std::ostream& os) override;
    virtual std::ostream& writeTxt(std::ostream& os, int tab = 0) override;
  };
}
