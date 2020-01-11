#pragma once

#include <unordered_map>
#include <variant>
#include <vector>

#include "../chklib/MappingCore.h"

namespace llvmbw {
  class TriggerBlock {
  private:
    std::vector<Chk::Condition> conditions;
    std::vector<Chk::Action> actions;
  public:

  };
}