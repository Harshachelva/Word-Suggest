#include <iostream>
#include <fstream>
#include <cstring>
#include "trie.h"

void loadFromFile(Node* root, const char* filename) {
    std::ifstream file(filename);
    std::string word;
    while (file >> word) {
        insert(root, word.c_str());
    }
    file.close();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <prefix>" << std::endl;
        return 1;
    }

    char* prefix = argv[1];
    Node* rootCommon = createNode();
    Node* rootAll = createNode();
    char buffer[100];
    int count = 0;

    // Load common words and search
    loadFromFile(rootCommon, "common-words.txt");
    Node* prefixNode = searchPrefix(rootCommon, prefix);
    if (prefixNode) {
        std::cout << "Suggestions from common-words.txt:" << std::endl;
        findWords(prefixNode, buffer, strlen(prefix), &count);
    } else {
        std::cout << "No suggestions found in common-words.txt." << std::endl;
    }

    // If not enough suggestions, load all words and search
    if (count < MAX_SUGGESTION) {
        loadFromFile(rootAll, "all-words.txt");
        prefixNode = searchPrefix(rootAll, prefix);
        if (prefixNode) {
            std::cout << "Suggestions from all-words.txt:" << std::endl;
            findWords(prefixNode, buffer, strlen(prefix), &count);
        } else {
            std::cout << "No suggestions available in all-words.txt!" << std::endl;
        }
    }

    if (count == 0) {
        std::cout << "No suggestions available!" << std::endl;
    }

    // Free allocated memory (omitted for brevity)

    return 0;
}
