#include "trie.h"
#include "test_helpers.h"

void test_create_destroy(void) {
    Trie *trie = trie_create();
    ASSERT_BOOL_EQ(trie != NULL, true, "Create trie");
    trie_destroy(trie);
    test_passed++;
    printf("  " COLOR_GREEN "✓ Destroy trie" COLOR_RESET "\n");
}

void test_insert_and_search(void) {
    Trie *trie = trie_create();
    trie_insert(trie, "hello");
    ASSERT_BOOL_EQ(trie_search(trie, "hello"), true, "Search inserted word");
    ASSERT_BOOL_EQ(trie_search(trie, "world"), false, "Search non-existent word");
    trie_destroy(trie);
}

void test_prefix_not_word(void) {
    Trie *trie = trie_create();
    trie_insert(trie, "hello");
    ASSERT_BOOL_EQ(trie_search(trie, "hel"), false, "Prefix is not complete word");
    ASSERT_BOOL_EQ(trie_starts_with(trie, "hel"), true, "Starts with prefix");
    trie_destroy(trie);
}

void test_starts_with(void) {
    Trie *trie = trie_create();
    trie_insert(trie, "apple");
    trie_insert(trie, "app");
    ASSERT_BOOL_EQ(trie_starts_with(trie, "app"), true, "Starts with existing prefix");
    ASSERT_BOOL_EQ(trie_starts_with(trie, "appl"), true, "Starts with partial word");
    ASSERT_BOOL_EQ(trie_starts_with(trie, "ban"), false, "Starts with non-existent prefix");
    trie_destroy(trie);
}

void test_delete_word(void) {
    Trie *trie = trie_create();
    trie_insert(trie, "hello");
    trie_insert(trie, "hell");
    trie_delete(trie, "hello");
    ASSERT_BOOL_EQ(trie_search(trie, "hello"), false, "Deleted word not found");
    ASSERT_BOOL_EQ(trie_search(trie, "hell"), true, "Shorter word still exists");
    trie_destroy(trie);
}

void test_multiple_words(void) {
    Trie *trie = trie_create();
    const char *words[] = {"cat", "car", "card", "care", "careful", "dog"};
    for (int i = 0; i < 6; i++) {
        trie_insert(trie, words[i]);
    }

    ASSERT_BOOL_EQ(trie_search(trie, "car"), true, "Multiple words - car");
    ASSERT_BOOL_EQ(trie_search(trie, "card"), true, "Multiple words - card");
    ASSERT_BOOL_EQ(trie_search(trie, "dog"), true, "Multiple words - dog");
    ASSERT_BOOL_EQ(trie_starts_with(trie, "ca"), true, "Multiple words - ca prefix");
    trie_destroy(trie);
}

void test_empty_string(void) {
    Trie *trie = trie_create();
    trie_insert(trie, "");
    ASSERT_BOOL_EQ(trie_search(trie, ""), true, "Empty string");
    trie_destroy(trie);
}

int main(void) {
    printf(COLOR_BOLD "Running trie tests:\n" COLOR_RESET);

    test_create_destroy();
    test_insert_and_search();
    test_prefix_not_word();
    test_starts_with();
    test_delete_word();
    test_multiple_words();
    test_empty_string();

    PRINT_TEST_SUMMARY("trie");
    return test_failed > 0 ? 1 : 0;
}
