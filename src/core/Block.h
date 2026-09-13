#ifndef TEST_CHAIN_BLOCK_H
#define TEST_CHAIN_BLOCK_H

#include <cstdint>    // To standardize data type sizes
#include <iostream>   // For input and output
#include <sstream>
#include <string>
#include <ctime>

class Block {
  public:
    std::string prevHash;  // Store previous block's hash
    Block(uint32_t indexIn, const std::string &dataIn);  // Constructor
    std::string GetHash() const; // Getter of private property Hash
    void MineBlock(uint32_t difficulty);  // Find valid Nonce and calculating Hash
  private:
    uint32_t Index;   // Position in chain
    int64_t Nonce;    // Value to further complicate hash. Essentially a salt of sorts
    std::string Data;      // Block's content
    std::string Hash;      // Block's Hash
    time_t Time;      // Time of Block's Creation
    std::string CalculateHash() const; // Calculate Hash
};

#endif
