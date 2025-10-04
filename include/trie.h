#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>

typedef struct Trie Trie;

Trie* trie_create(void);
void trie_insert(Trie *trie, const char *word);
bool trie_search(const Trie *trie, const char *word);
bool trie_starts_with(const Trie *trie, const char *prefix);
void trie_delete(Trie *trie, const char *word);
void trie_destroy(Trie *trie);

#endif // TRIE_H
