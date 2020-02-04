#include "TrigMemBlock.h"

#include "./../../chklib/MappingCore.h"
#include "../Util.h"

#include <vector>
#include <cstdint>

namespace llvmbw {
  constexpr size_t FASTVAR_STAGGER = 528;
  constexpr size_t FASTVAR_COND_OFFSET = 332;
  constexpr size_t MAX_VARS = 5957;
  constexpr size_t FASTVAR_SIZE = 2740;

  static_assert(FASTVAR_COND_OFFSET + sizeof(Chk::MemTrigger) == FASTVAR_SIZE);

  class FastVarArray : public TrigMemBlock {
  private:
    std::vector<uint8_t> data;
  public:
    FastVarArray(size_t num_elements)
      : data{ FASTVAR_SIZE + FASTVAR_STAGGER * (num_elements - 1), 0 }
    {
      require(num_elements > 0 && num_elements <= MAX_VARS, "num_elements out of range");
    }


  };
}