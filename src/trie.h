#ifndef TRIE_H
#define TRIE_H

#define ALPHABET_SIZE 26
#define MAX_SUGGESTION 5

typedef struct Node {
    struct Node* children[ALPHABET_SIZE];
    bool isEnd;
} Node;

Node* createNode();
void insert(Node* root, const char* word);
Node* searchPrefix(Node* root, const char* prefix);
void findWords(Node* root, char* buffer, int depth, int* count);

#endif
