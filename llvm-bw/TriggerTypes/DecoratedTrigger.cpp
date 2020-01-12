#include "DecoratedTrigger.h"

#include <cstddef>

using namespace llvmbw;

unsigned DecoratedTrigger::current_id = 1;

DecoratedTrigger::DecoratedTrigger()
  : id(current_id++)
{
  this->ptrRelocationOffsets.insert(offsetof(Chk::MemTrigger, next));
}
