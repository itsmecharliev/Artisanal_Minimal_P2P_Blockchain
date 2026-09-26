#include "./core/Blockchain.h"

using namespace std;

int main() {
  Blockchain Chain = Blockchain();

  cout << "Mining block 1..." << endl;
  Chain.AddBlock(Block(1, "Block 1 Data"));

  cout << "Mining block 2..." << endl;
  Chain.AddBlock(Block(2, "Block 2 Data"));

  cout << "Mining block 3..." << endl;
  Chain.AddBlock(Block(3, "Block 3 Data"));

  return 0;
}
