#pragma once

#include "../chklib/MappingCore.h"

namespace llvmbw {
  enum class ExtActionType {
    no_op,
    go_to
  };

  class ExtTriggerAction : public Chk::Action {
  private:
    bool fake = false;
    ExtActionType type = ExtActionType::no_op;
  };
}
