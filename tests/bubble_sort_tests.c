#include "include/bubble_sort.h"

#define DEFINE_RKTEST_IMPLEMENTATION
#include "include/rktest.h"

TEST(bubble_sort, bubble_sort_works) {
    int expected[] = {3, 4, 7, 9, 42, 69, 420};
    int actual[] = {9, 3, 7, 4, 69, 420, 42};

    bubble_sort(actual, 7);

    for (size_t i = 0; i < 7; ++i) {
        EXPECT_EQ(actual[i], expected[i]);
    }
}

int main(int argc, const char *argv[]) {
    return rktest_main(argc, argv);
}
