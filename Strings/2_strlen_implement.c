#include <stdio.h>
#include <string.h>

/*
 * Version 1:
 * Calculate string length using array indexing.
 *
 * Logic:
 *  - Start from index 0.
 *  - Count characters until '\0' is found.
 */
#if 0
long int my_strlen(char *str)
{
        long int count = 0;
        int i = 0;

        while (str[i] != '\0') {
                count++;
                i++;
        }

        return count;
}

/*
 * Version 2:
 * Calculate length using pointer arithmetic.
 *
 * Logic:
 *  - Save the starting address.
 *  - Move the pointer until '\0' is reached.
 *  - Subtract start address from current address.
 *
 * Note:
 *  - Casting pointers to long int is not portable.
 *  - Prefer direct pointer subtraction instead.
 */
long int my_strlen(char *str)
{
        long int st = (long int)str;

        while (*str != '\0') {
                str++;
        }

        return (long int)str - st;
}
#endif

/*
 * Version 3 (Recommended):
 * Uses pointer subtraction directly.
 *
 * Parameters:
 *      str - Pointer to a null-terminated string.
 *
 * Returns:
 *      Length of the string excluding '\0'.
 *
 * Why size_t?
 *      - It is the standard type used for sizes and lengths.
 *      - strlen() also returns size_t.
 */
size_t my_strlen(char *str)
{
        /* Remember the starting position of the string */
        char *start = str;

        /*
         * Advance the pointer until the null terminator
         * is encountered.
         */
        while (*str) {
                str++;
        }

        /*
         * Pointer subtraction gives the number of characters
         * between start and str.
         *
         * Example:
         *      "hello"
         *
         *      start --> 'h'
         *      str   --> '\0'
         *
         *      str - start = 5
         */
        return str - start;
}

int main()
{
        /* Buffer capable of holding 9 chars + '\0' */
        char str[10];

        printf("Enter a string\n");

        /*
         * Read at most 9 characters.
         * The 10th byte is reserved for '\0'.
         *
         * Example:
         *      Input: "embedded"
         *      Stored: "embedded\0"
         */
        scanf("%9s", str);

        /* Standard library implementation */
        printf("String length using strlen is: %lu\n", strlen(str));

        /* Custom implementation */
        printf("String length using my_strlen is: %lu\n", my_strlen(str));

        return 0;
}
