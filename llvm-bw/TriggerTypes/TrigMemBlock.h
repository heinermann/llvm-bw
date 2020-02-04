#pragma once

#include <set>

namespace llvmbw {

  class TrigMemBlock {
  public:
    std::set<size_t> ptrRelocationOffsets;
    std::set<size_t> groupRelocationOffsets;

    virtual ~TrigMemBlock() {}
  };
}
