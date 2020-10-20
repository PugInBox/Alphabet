#include "../src/alphabet.h"
#include "../thirdparty/ctest.h"

CTEST(sort_check, main_sort)
{
    int i, j, k;
    char expected[MAX_LENGTH_STRING * MAX_LENGTH_STRING];
    char a[MAX_LENGTH_STRING][MAX_LENGTH_STRING];
    char real[MAX_LENGTH_STRING * MAX_LENGTH_STRING] = "abc";
    FILE* f = fopen("test.txt", "r");
    if (f == NULL) {
        return ERROR_OPEN_FILE;
    }
    int count = check_file(f, a);
    k = 0;
    for (i = 0; i < sizeof a / sizeof *a; ++i)
        for (j = 0; j < sizeof a[0] / sizeof **a; ++j) {
            expected[k] = a[i][j];
            ++k;
        }
    ASSERT_STR(expected, real);
}

CTEST(function_check, UpperToLower)
{
    char expected[MAX_LENGTH_STRING] = "hello world";
    char real[MAX_LENGTH_STRING] = "HELLO WORLD";
    UpperToLower(real);
    ASSERT_STR(expected, real);
}
