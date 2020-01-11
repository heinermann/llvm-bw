#include "include/builtins.h"

int someGlobal = 5;

int main()
{
  *((short*)0x0057F1DC) = 1;    // set to space tileset
  *((short*)0x006509A0) = 0;    // invoke perfect tick hypers

  for (int i = 0; i < 10; ++i) {
    MinimapPing(0);
  }
}
