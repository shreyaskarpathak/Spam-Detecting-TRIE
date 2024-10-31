#pragma once

#include "Node.h"
#include <string>

class Trie {
public:
    Trie() {                        // Constructor
        root = new TrieNode();
    }                   
    void insert(const std::string& word) // Insert a word into the trie
    {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }
    bool search(const std::string& word) {   //search for word in tree
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                return false;  // If any character is missing, word does not exist
            }
            current = current->children[ch];
        }
        // Check if the final node marks the end of a word
        return current->isEndOfWord;
    }
    bool remove(const std::string& word) { // Wrapper function for removing a word
        return remove(root, word, 0);
    }

private:
    TrieNode* root;

    bool remove(TrieNode* node, const std::string& word, int depth) {
        // Base case: if the trie is empty
        if (!node) return false;

        // If we've reached the end of the word
        if (depth == word.size()) {
            // This node is no longer the end of the word
            if (node->isEndOfWord) node->isEndOfWord = false;

            // Check if this node has no children
            if (node->children.empty()) {
                delete node;
                return true; // Node can be deleted
            }
            return false; // Node cannot be deleted as it has children
        }

        // Recursively delete the child node
        char ch = word[depth];
        if (node->children.find(ch) != node->children.end()) {
            bool shouldDeleteChild = remove(node->children[ch], word, depth + 1);

            // If true, delete the child node reference
            if (shouldDeleteChild) {
                node->children.erase(ch);

                // Return true if no children remain and this node is not the end of another word
                return node->children.empty() && !node->isEndOfWord;
            }
        }
        return false;
    }
};

