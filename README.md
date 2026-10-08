### Dependencies needed:
g++, make

### one liner compile for Linux:
g++ -std=c++17 -pthread -O2 -Wall -Wextra main.cpp core/*.cpp cryptography/*.cpp network/*.cpp -o TestChain

### one liner compile for mac:
clang++ -std=c++17 -pthread -O2 -Wall -Wextra main.cpp core/*.cpp cryptography/*.cpp network/*.cpp -o TestChain

### How to Run:
./TestChain <my_p2p_port> <peer_ip> <peer_p2p_port>

### Laptop A
./TestChain 6001 192.168.1.11 6001

### Laptop B
./TestChain 6001 192.168.1.10 6001

# References
The initial creation of this code started off as a tutorial by Dave Nash
in his [BUILD A BLOCKCHAIN WITH C++](https://davenash.com/2017/10/build-a-blockchain-with-c/) tutorial.

The [SHA256](https://www.zedwood.com/article/cpp-sha256-function) function that I imported is from zedwood.
