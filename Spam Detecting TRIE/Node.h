#pragma once
#include <unordered_map>
#include <string>
#include <vector>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;  // Map for child nodes
    bool isEndOfWord;                              // Indicates end of a word

    TrieNode() : isEndOfWord(false) {}             // Initialize isEndOfWord as false
};
