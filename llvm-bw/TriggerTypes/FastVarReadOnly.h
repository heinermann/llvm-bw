#pragma once
#include "DecoratedTrigger.h"
#include "TriggerGenerator.h"
#include "../../chklib/MappingCore.h"

#include <cstdint>
#include <cstddef>
#include <optional>

namespace llvmbw {
  class FastVarReadOnly : DecoratedTrigger {
  public:
    FastVarReadOnly(
      uint32_t branch_true,
      uint32_t branch_false,
      uint32_t initialValue = 0,
      uint32_t initialTargetPlayer = 0,
      Chk::Condition::Comparison initialComparison = Chk::Condition::Comparison::Exactly
    ) : DecoratedTrigger()
    {
      using namespace ConditionGen;
      using namespace ActionGen;

      this->trig.trigger = TriggerGen::Trigger()
        .Conditions({
          Deaths(initialTargetPlayer, Chk::Condition::Comparison::Exactly, initialValue, 0)
        }).Actions({
          SetDeaths(offsetof(Chk::MemTrigger, Chk::Action::ValueModifier::SetTo, 0, 0)
        });

      this->groupRelocationOffsets.insert(offsetof(Chk::MemTrigger, trigger.actions[0].group));
    }
    virtual ~FastVarReadOnly() override {}

    virtual std::optional<size_t> getValueOffset() override {
      return offsetof(Chk::MemTrigger, trigger.actions[0].number);
    }
  };
}
