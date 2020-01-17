#pragma once

#include <cstdint>

namespace llvmbw::Offsets {
    /**
      * Returns true if the given offset can be written to in Remastered.
      */
    bool CanWrite(uint32_t offset, uint32_t numBytes = 4);
    
    /**
      * Returns true if the given offset can be read in Remastered.
      */
    bool CanRead(uint32_t offset, uint32_t numBytes = 4);

    /**
      * Returns true if reading this value ensures that players will
      * not become desynced and drop from the game.
      */
    bool IsSync(uint32_t offset, uint32_t numBytes = 4);
}
