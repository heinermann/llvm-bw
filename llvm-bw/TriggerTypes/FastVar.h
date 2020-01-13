#include "FastVarReadOnly.h"
#include "FastVarWriteOnly.h"

namespace llvmbw {
  class FastVar {
    FastVarReadOnly read;
    FastVarWriteOnly write;
  };
}