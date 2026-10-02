#ifndef NETWORK_PROTOCOL_H
#define NETWORK_PROTOCOL_H

#include <string>
#include <vector>
#include <sstream>
#include "../core/Block.h"

/*
 * Format:
 * <message type byte><payload>\n
 * Payload is pipe-delimited fields.
 * Frames are newline-terminated so the receiver can split.
 */


/*
 * Message types:
 * 'G' - an empty payload -> Request peer's full blockchain.
 * 'B' - a block payload -> One frame per block, sent in response to GetBlocks.
 * 'N' - a block payload -> Announces appended block and append block if valid.
 */
enum class MessageType : uint8_t {
  GetBlocks = 'G',
  Block = 'B',
  NewBlock = 'N'
};

/*
 * Block Payload Layout:
 * index - block height
 * time - unix timestamp
 * nonce - mining counter
 * prevHash - hash of parent block
 * data - block payload
 * hash - current block's hash
 */
inline std::string SerializeBlock(const Block& block) {
  std::ostringstream oss;

  oss <<  block.GetIndex()  <<  '|'
      <<  block.GetTime()   <<  '|'
      <<  block.GetNonce()  <<  '|'
      <<  block.prevHash    <<  '|'
      <<  block.GetData()   <<  '|'
      <<  block.GetHash();

  return oss.str()
}

inline Block DeserializeBlock(const std::string& payload) {
  std::istringstream iss(payload);
  std::string token;
  Block block;

  // Covert these 3 as end data type is not a string
  std::getline(iss, token, '|');
  block.SetIndex(static_cast<uint32_t>(std::stoul(token)));

  std::getline(iss, token, '|');
  block.SetTime(static_cast<time_t>(std::stol(token)));

  std::getline(iss, token, '|');
  block.SetNonce(std::stoll(token));

  // No need to convert because end result is a string
  std::getline(iss, token, '|');
  block.prevHash = token;

  std::getline(iss, token, '|');
  block.SetData(token);

  std::getline(iss, token, '|');
  block.SetHash(token);

  return block;
}

inline std::string MakeFrame(MessageType type, const std::string& payload) {
  std::string frame;

  // prepares room for: message type + payload + end of frame
  frame.reserve(payload.size() + 2);

  frame.push_back(static_cast<char>(type)); // message type
  frame.append(payload);                    // payload
  frame.push_back('\n');                    // end of frame

  return frame;
}

