#pragma once
#include "TrigInst.h"

namespace llvmbw {
  class ConstPtr : public TrigInst {
  private:
    uint32_t value;
    uint32_t bitmask;

  public:
    ConstPtr(uint32_t _value, uint32_t _bitmask = 0xFFFFFFFF)
      : TrigInst(TrigInst::Type::ConstPtr)
      , value(_value)
      , bitmask(_bitmask)
    {}

    virtual ~ConstPtr() override {}

    virtual bool optimizationPass() override;
    virtual std::ostream& writeDot(std::ostream& os) override;
    virtual std::ostream& writeTxt(std::ostream& os, int tab = 0) override;
  };
}
