#pragma once
#include <set>
#include <iostream>
#include <optional>
#include "../../chklib/MappingCore.h"

namespace llvmbw {

  class DecoratedTrigger {
  private:
    static unsigned current_id;
  public:
    unsigned id;
    Chk::MemTrigger trig = {};

    std::set<size_t> ptrRelocationOffsets;
    std::set<size_t> groupRelocationOffsets;

    DecoratedTrigger();

    virtual std::optional<size_t> getValueOffset() {
      return std::nullopt;
    }
  };
}
