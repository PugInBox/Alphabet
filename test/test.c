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
