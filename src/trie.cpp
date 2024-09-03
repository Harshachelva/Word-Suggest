#include <iostream>
#include <cstring>
#include "trie.h"

Node* createNode() {
    Node* newNode = new Node();
    newNode->isEnd = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        newNode->children[i] = nullptr;
    }
    return newNode;
}

void insert(Node* root, const char* word) {
    Node* currentNode = root;
    int index;
    int length = strlen(word);

    for (int level = 0; level < length; level++) {
        index = word[level] - 'a';
        if (currentNode->children[index] == nullptr) {
            currentNode->children[index] = createNode();
        }
        currentNode = currentNode->children[index];
    }
    currentNode->isEnd = true;
}

Node* searchPrefix(Node* root, const char* prefix) {
    Node* currentNode = root;
    int length = strlen(prefix);
    int index;

    for (int level = 0; level < length; level++) {
        index = prefix[level] - 'a';
        if (currentNode->children[index] == nullptr) {
            return nullptr;
        }
        currentNode = currentNode->children[index];
    }
    return currentNode;
}

void findWords(Node* root, char* buffer, int depth, int* count) {
    if (root->isEnd) {
        buffer[depth] = '\0';
        std::cout << buffer << std::endl;
        (*count)++;
        if (*count >= MAX_SUGGESTION) return;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i] != nullptr) {
            buffer[depth] = 'a' + i;
            findWords(root->children[i], buffer, depth + 1, count);
            if (*count >= MAX_SUGGESTION) return;
        }
    }
}
