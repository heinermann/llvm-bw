#pragma once
#include "TrigInst.h"

#include <cstdint>

namespace llvmbw {
  class Constant : public TrigInst {
  private:
    uint32_t value;
    uint32_t bitmask;

  public:
    Constant(uint32_t _value, uint32_t _bitmask = 0xFFFFFFFF)
      : TrigInst(TrigInst::Type::Constant)
      , value(_value)
      , bitmask(_bitmask)
    {}

    virtual ~Constant() override {}

    virtual bool optimizationPass() override;
    virtual std::ostream& writeDot(std::ostream& os) override;
    virtual std::ostream& writeTxt(std::ostream& os, int tab = 0) override;
  };
}
