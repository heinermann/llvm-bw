#pragma once
#include "TrigInst.h"

#include <memory>
#include <optional>

namespace llvmbw {
  class Retn : public TrigInst {
  private:
    std::optional<std::shared_ptr<TrigInst>> value;

  public:
    Retn(std::optional<std::shared_ptr<TrigInst>> _value = std::nullopt)
      : TrigInst(TrigInst::Type::Retn)
      , value(_value)
    {}

    virtual ~Retn() override {}

    virtual bool optimizationPass() override;
    virtual std::ostream& writeDot(std::ostream& os) override;
    virtual std::ostream& writeTxt(std::ostream& os, int tab = 0) override;
  };
}
