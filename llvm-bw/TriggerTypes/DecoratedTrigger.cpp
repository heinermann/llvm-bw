#include "DecoratedTrigger.h"

#include <cstddef>

using namespace llvmbw;

//unsigned DecoratedTrigger::current_id = 1;

DecoratedTrigger::DecoratedTrigger(unsigned _id)
  : id(_id)
{
  this->ptrRelocationOffsets.insert(offsetof(Chk::MemTrigger, next));
}
