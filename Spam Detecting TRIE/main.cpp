#include <iostream>
#include "Trie.h"

void runTests() {
    Trie trie;

    // Insert words into the trie
    std::cout << "Inserting words: 'car', 'cat', 'dog', 'cart', 'can'\n";
    trie.insert("car");
    trie.insert("cat");
    trie.insert("dog");
    trie.insert("cart");
    trie.insert("can");

    // Test insert and search functionality
    std::cout << "\nSearch Tests:\n";
    std::cout << "Search 'car': " << trie.search("car") << " (Expected: 1)\n";
    std::cout << "Search 'cat': " << trie.search("cat") << " (Expected: 1)\n";
    std::cout << "Search 'dog': " << trie.search("dog") << " (Expected: 1)\n";
    std::cout << "Search 'cart': " << trie.search("cart") << " (Expected: 1)\n";
    std::cout << "Search 'can': " << trie.search("can") << " (Expected: 1)\n";
    std::cout << "Search 'ca': " << trie.search("ca") << " (Expected: 0)\n";
    std::cout << "Search 'cartoon': " << trie.search("cartoon") << " (Expected: 0)\n";

    // Test remove functionality
    std::cout << "\nRemove Tests:\n";
    std::cout << "Removing 'cat'\n";
    trie.remove("cat");
    std::cout << "Search 'cat': " << trie.search("cat") << " (Expected: 0)\n"; // cat should be removed
    std::cout << "Search 'car': " << trie.search("car") << " (Expected: 1)\n"; // car should remain intact
    std::cout << "Search 'cart': " << trie.search("cart") << " (Expected: 1)\n"; // cart should remain intact

    std::cout << "\nRemoving 'cart'\n";
    trie.remove("cart");
    std::cout << "Search 'cart': " << trie.search("cart") << " (Expected: 0)\n"; // cart should be removed
    std::cout << "Search 'car': " << trie.search("car") << " (Expected: 1)\n"; // car should still be there

    std::cout << "\nRemoving non-existent word 'bat'\n";
    trie.remove("bat"); // Should not affect the trie
    std::cout << "Search 'bat': " << trie.search("bat") << " (Expected: 0)\n"; // bat is not in the trie
    std::cout << "Search 'dog': " << trie.search("dog") << " (Expected: 1)\n"; // dog should still be there
}

int main() {
    runTests();
    return 0;
}
