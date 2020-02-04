#pragma once
#include <set>
#include <optional>

#include "TrigMemBlock.h"

#include "../../chklib/MappingCore.h"

namespace llvmbw {

  class DecoratedTrigger : public TrigMemBlock {
  private:
    //static unsigned current_id;
  public:
    unsigned id;
    Chk::MemTrigger trig = {};

    DecoratedTrigger(unsigned id);
    virtual ~DecoratedTrigger() {};

    virtual std::optional<size_t> getValueOffset() {
      return std::nullopt;
    }
  };
}
