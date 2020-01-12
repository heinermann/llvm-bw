#pragma once

#include "./Chkdraft/MappingCoreLib/MappingCore.h"

namespace Chk {
#pragma pack(push, 1)

  __declspec(align(1)) struct MemTrigger {
    uint32_t prev;
    uint32_t next;
    Trigger trigger;
  };

#pragma pack(pop)
}
