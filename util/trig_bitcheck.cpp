#include <bitset>
#include <iostream>

// 2740 bytes per overlapped read/write triggers
constexpr int OVERLAP_BYTES = 2740 * 3;

using TrigSet = std::bitset<OVERLAP_BYTES>;
TrigSet trigBase;

void initTriggerUse() {
  // W: prev
  // trigBase[0] = true;
  // trigBase[1] = true;
  // trigBase[2] = true;
  // trigBase[3] = true;
  // W: next
  trigBase[4] = true;
  trigBase[5] = true;
  trigBase[6] = true;
  trigBase[7] = true;
  // W: empty condition
  trigBase[23] = true;
  trigBase[25] = true;
  // W: bitmask
  trigBase[328] = true;
  trigBase[329] = true;
  trigBase[330] = true;
  trigBase[331] = true;
  // W: group
  trigBase[344] = true;
  trigBase[345] = true;
  trigBase[346] = true;
  trigBase[347] = true;
  // W: number
  trigBase[348] = true;
  trigBase[349] = true;
  trigBase[350] = true;
  trigBase[351] = true;
  // W: type/action/modifier
  trigBase[352] = true;
  trigBase[353] = true;
  trigBase[354] = true;
  trigBase[355] = true;
  // W: flags and mask requirement
  trigBase[356] = true;
  trigBase[357] = true;
  trigBase[358] = true;
  // W: empty action
  trigBase[386] = true;
  trigBase[388] = true;
  // W: trigger flag & current trigger
  trigBase[2376] = true;
  trigBase[2407] = true;

  // R: prev
  // trigBase[332] = true;
  // trigBase[333] = true;
  // trigBase[334] = true;
  // trigBase[335] = true;
  // R: next
  trigBase[336] = true;
  trigBase[337] = true;
  trigBase[338] = true;
  trigBase[339] = true;
  // R: bitmask
  trigBase[340] = true;
  trigBase[341] = true;
  trigBase[342] = true;
  trigBase[343] = true;
  // R: group
  trigBase[344] = true;
  trigBase[345] = true;
  trigBase[346] = true;
  trigBase[347] = true;
  // R: number
  trigBase[348] = true;
  trigBase[349] = true;
  trigBase[350] = true;
  trigBase[351] = true;
  // R: unitType/comparison/condition
  trigBase[352] = true;
  trigBase[353] = true;
  trigBase[354] = true;
  trigBase[355] = true;
  // R: flags and mask requirement
  trigBase[357] = true;
  trigBase[358] = true;
  trigBase[358] = true;
  // R: empty condition
  trigBase[375] = true;
  trigBase[377] = true;
  // R: jmp group
  trigBase[676] = true;
  trigBase[677] = true;
  trigBase[678] = true;
  trigBase[679] = true;
  // R: jmp number
  trigBase[680] = true;
  trigBase[681] = true;
  trigBase[682] = true;
  trigBase[683] = true;
  // R: jmp type/action/modifier
  trigBase[684] = true;
  trigBase[685] = true;
  trigBase[686] = true;
  trigBase[687] = true;
  // R: jmp flags
  trigBase[688] = true;
  // R: empty action
  trigBase[718] = true;
  trigBase[720] = true;
  // R: trigger flags & current trigger
  trigBase[2708] = true;
  trigBase[2739] = true;
}

bool computeOverlap(TrigSet currentOverlap, int currentOffset, int step) {
  if (currentOffset >= OVERLAP_BYTES) return true;

  TrigSet target = trigBase >> currentOffset;
  if ((currentOverlap & target).none()) {
    return computeOverlap(currentOverlap | target, currentOffset + step, step);
  }
  return false;
}

int main()
{
  initTriggerUse();
  for (int i = 4; i <= OVERLAP_BYTES; i += 4) {
    if (computeOverlap(trigBase, i, i)) {
      if (i % (12*4) == 0) {
        std::cout << "* ";
      } else {
        std::cout << "  ";
      }
      std::cout << i << std::endl;
    }
  }
  std::cout << "Done!" << std::endl;
}

