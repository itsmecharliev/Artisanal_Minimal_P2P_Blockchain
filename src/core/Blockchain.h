#ifndef TEST_CHAIN_BLOCKCHAIN_H
#define TEST_CHAIN_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Block.h"

using namespace std;

class Blockchain {
  public:
    Blockchain();                   // Constructor
    void AddBlock(Block newBlock);  // Adding new Block to Blockchain
  private:
    uint32_t Difficulty;            // Desired Blockchain difficulty
    vector<Block> Chain;            // Chain of Blocks
    Block GetLastBlock() const;     // Obtain last block
};

#endif
