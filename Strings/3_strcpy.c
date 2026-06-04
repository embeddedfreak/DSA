#include <stdio.h>
#include <string.h>

#if 0
/*
 * My implementation of strcpy().
 *
 * Logic:
 *      1. Copy the current character from source to destination.
 *      2. Check whether the current source character is '\0'.
 *      3. If not, move to the next character and continue.
 *      4. When '\0' is copied, stop.
 *
 * Note:
 *      src_str++ in the while condition uses post-increment:
 *      - First evaluates *src_str.
 *      - Then advances src_str to the next character.
 */
void my_strcpy(char *dst_str, char *src_str)
{
        do {
                *dst_str++ = *src_str;
        } while (*src_str++);
}
#endif

/*
 * Standard/idiomatic implementation of strcpy().
 *
 * The expression:
 *
 *      *dst_str++ = *src_str++
 *
 * performs three actions:
 *
 *      1. Copy the character pointed to by src_str.
 *      2. Store it at the location pointed to by dst_str.
 *      3. Advance both pointers to the next character.
 *
 * Assignment expressions return the value assigned.
 *
 * Example:
 * 	If while(x = 5)
 *
 * 	it will give the value copied so 5
 *
 *      If 'A' is copied,
 *
 *          (*dst_str++ = *src_str++)
 *
 *      evaluates to 'A'.
 *
 * The loop continues until the copied character is '\0'.
 *
 * When '\0' is copied:
 *
 *      ('\0' != '\0')
 *
 * becomes false and the loop terminates.
 *
 * This ensures the null terminator is also copied,
 * making the destination a valid C string.
 */
void my_strcpy(char *dst_str, char *src_str)
{
        while ((*dst_str++ = *src_str++) != '\0')
                ;
}

int main()
{
        /*
         * Source string entered by the user.
         * Destination buffer where the copied string
         * will be stored.
         */
        char str[10], str_cp[10];

        printf("Enter a string to copy:\n");

        /*
         * Read at most 9 characters and reserve
         * one byte for the terminating '\0'.
         *
         * Using "%9s" prevents buffer overflow.
         */
        scanf("%9s", str);

        /* Copy source string into destination buffer */
        my_strcpy(str_cp, str);

        /* Display copied string */
        printf("String after copy: %s\n", str_cp);

        return 0;
}
