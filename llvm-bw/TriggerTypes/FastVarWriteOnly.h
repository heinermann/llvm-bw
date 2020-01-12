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
      this->trig.trigger.condition[0] = ConditionGen::NoCondition();
      this->trig.trigger.actions[0] = ActionGen::SetDeaths(initialTargetPlayer, initialModifier, initialValue, 0);
      this->trig.trigger.actions[1] = ActionGen::NoAction();
    }

    virtual std::optional<size_t> getValueOffset() override {
      return offsetof(Chk::MemTrigger, trigger.actions[0].number);
    }
  };
}
