#pragma once
#include "DecoratedTrigger.h"
#include "TriggerGenerator.h"
#include "../../chklib/MappingCore.h"

#include <cstdint>
#include <cstddef>
#include <optional>

namespace llvmbw {
  class FastVarWriteOnly : DecoratedTrigger {
  public:
    FastVarWriteOnly(
      uint32_t next,
      uint32_t initialValue = 0,
      uint32_t initialTargetPlayer = 0,
      Chk::Action::ValueModifier initialModifier = Chk::Action::ValueModifier::SetTo
    ) : DecoratedTrigger()
    {
      using namespace ActionGen;

      this->trig.trigger = TriggerGen::Trigger()
        .Actions({
          SetDeaths(initialTargetPlayer, initialModifier, initialValue, 0)
        });
    }
    virtual ~FastVarWriteOnly() override {}

    virtual std::optional<size_t> getValueOffset() override {
      return offsetof(Chk::MemTrigger, trigger.actions[0].number);
    }
  };
}
