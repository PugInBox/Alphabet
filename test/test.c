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
CTEST(ENG_words_check, register_check_1)
{
    char expected[] = "hello";
    char result[] = "HELLO";
    for (int i = 0; i < 5; i++) {
        result[i] = tolower(result[i]);
    }
    ASSERT_STR(expected, result);
}
CTEST(ENG_words_check, register_check_2)
{
    char expected[] = "HELLO";
    char result[] = "HELLO";
    for (int i = 0; i < 5; i++) {
        result[i] = tolower(result[i]);
    }
    ASSERT_STR(expected, result);
}
CTEST(RU_words_check, register_check_1)
{
    char expected[] = "привет";
    char result[] = "ПРИВЕТ";
    for (int i = 0; i < 5; i++) {
        result[i] = tolower(result[i]);
    }
    ASSERT_STR(expected, result);
}
CTEST(RU_words_check, register_check_2)
{
    char expected[] = "ПРИВЕТ";
    char result[] = "ПРИВЕТ";
    for (int i = 0; i < 5; i++) {
        result[i] = tolower(result[i]);
    }
    ASSERT_STR(expected, result);
}