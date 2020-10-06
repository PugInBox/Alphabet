#include "../src/alphabet.h"
#include "../thirdparty/ctest.h"

CTEST(file_check, file_exist)
{
    FILE* result = fopen("../input.txt", "r");
    if (result == NULL) {
        result = 0;
    }
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(file_check, file_dosnt_exist)
{
    FILE* result = fopen("input.txt", "r");
    if (result == NULL) {
        result = 0;
    }
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(sort_check, words_count_equal)
{
    char strings[100][100], str[200];
    int expected = 3;
    int result;
    FILE* f = open_file("test.txt", "r");
    if (f == NULL) {
        return NULL;
    }
    result = check_file(f, strings);
    ASSERT_EQUAL(expected, result);
}
CTEST(sort_check, words_count_not_equal)
{
    char strings[100][100], str[200];
    int expected = 12;
    int result;
    FILE* f = open_file("test.txt", "r");
    if (f == NULL) {
        return NULL;
    }
    result = check_file(f, strings);
    ASSERT_EQUAL(expected, result);
}