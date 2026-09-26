#include "Blockchain.h"

using namespace std;

Blockchain::Blockchain() {
  Chain.push_back(Block(0, "Genesis Block"));
  Difficulty = 3;   // 3 for test, 5-6 for demo
}

void Blockchain::AddBlock(Block newBlock) {
  newBlock.prevHash = GetLastBlock().GetHash();
  newBlock.MineBlock(Difficulty);
  Chain.push_back(newBlock);
}

Block Blockchain::GetLastBlock() const {
  return Chain.back();
}
