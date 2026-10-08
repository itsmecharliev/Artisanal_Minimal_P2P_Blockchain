#ifndef TEST_CHAIN_BLOCKCHAIN_H
#define TEST_CHAIN_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include <mutex>
#include "Block.h"

class Blockchain {
  public:
    Blockchain();                   // Constructor
    void AddBlock(Block newBlock);  // Adding new Block to Blockchain
    bool TryAddExternalBlock(const Block& block);
    std::vector<Block> Snapshot() const;

  private:
    uint32_t Difficulty;            // Desired Blockchain difficulty
    std::vector<Block> Chain;       // Chain of Blocks
    mutable std::mutex ChainMutex;
    Block GetLastBlock() const;     // Obtain last block
};

#endif
