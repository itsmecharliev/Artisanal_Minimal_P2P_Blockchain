#include "Block.h"
#include "../cryptography/sha256.h"

using namespace std;

Block::Block(uint32_t indexIn, const string &dataIn) : Index(indexIn), Data(dataIn) {
  Nonce = -1;
  Time = time(nullptr);
}

string Block::GetHash() const {
  return Hash;
}

void Block::MineBlock(uint32_t difficulty) {
  string str(difficulty, '0');  // Create string of length difficulty with char '0'

  // Calculate hash until we find enough prefix 0's meeting our difficulty
  do {
    Nonce++;
    Hash = CalculateHash();
  } while (Hash.substr(0, difficulty) != str);

  cout << "Block mined: " << Hash << endl;
}

string Block::CalculateHash() const {
  stringstream ss;
  ss << Index << Time << Data << Nonce << prevHash;

  return sha256(ss.str());
}
