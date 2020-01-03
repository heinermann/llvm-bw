void yield() {}

int someGlobal = 5;

int main()
{
  *((short*)0x0057F1DC) = 1;      // set to space tileset
  while(1) {
    *((short*)0x006509A0) = 0;    // invoke perfect tick hypers
    yield();
  }
}
