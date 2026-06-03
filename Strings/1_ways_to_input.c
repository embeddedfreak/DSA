#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    /* Method 1:
     * Character array initialized manually.
     * Programmer explicitly provides characters and NULL terminator.
     */
    char str1[10] = {'h','e','l','l','o','\0'};
    printf("str1: %s\n", str1);


    /* Method 2:
     * Character array initialized using string literal.
     * Compiler automatically adds '\0'.
     */
    char str2[] = "hello";
    printf("str2: %s\n", str2);


    /* Method 3:
     * Pointer pointing to string literal.
     * String literal usually stored in read-only memory.
     * Pointer can be reassigned but contents should not be modified.
     */
    char *str3 = "hello";
    printf("str3: %s\n", str3);


    /* Method 4:
     * String input using scanf("%s").
     * Reads input until first whitespace.
     * Width specifier prevents buffer overflow.
     *
     * Example input:
     * hello world
     *
     * Stored:
     * hello
     */
    char str4[20];

    printf("\nEnter str4 using scanf(\"%%s\") "
           "(try: hello world): ");

    scanf("%19s", str4);

    printf("str4: %s\n", str4);



    /* Method 4A:
     * String input using scanf scanset.
     *
     * %[...]
     * → scanset conversion specifier.
     *
     * [^\n]
     * → read everything UNTIL newline.
     *
     * Unlike "%s", scanset reads spaces.
     *
     * Example input:
     * hello world
     *
     * Stored:
     * hello world
     */

    /* Clear remaining input buffer */
    while(getchar() != '\n');

    char str4a[50];

    printf("\nEnter str4a using scanf(\"%%[^\\n]\") "
           "(try: hello world): ");

    scanf("%49[^\n]", str4a);

    printf("str4a: %s\n", str4a);



    /* Clear leftover newline before fgets() */
    getchar();


    /* Method 5:
     * Safe string input using fgets().
     * Reads spaces.
     * Reads at most (size-1) characters.
     * Stores newline ('\n') if space permits.
     *
     * strcspn():
     * Returns length of initial characters before
     * first occurrence of characters in search string.
     *
     * Here:
     * strcspn(str5,"\n")
     * finds newline inserted by fgets().
     *
     * Replacing newline with '\0'
     * removes trailing newline.
     */
    char str5[50];

    printf("\nEnter str5 using fgets(): ");

    fgets(str5, sizeof(str5), stdin);

    str5[strcspn(str5, "\n")] = '\0';

    printf("str5: %s\n", str5);


    /* Method 6:
     * Manual character assignment.
     * Programmer assigns characters individually.
     * NULL terminator must be added manually.
     */
    char str6[10];

    str6[0]='h';
    str6[1]='e';
    str6[2]='l';
    str6[3]='l';
    str6[4]='o';
    str6[5]='\0';

    printf("str6: %s\n", str6);


    /* Method 7:
     * Dynamic string allocation using malloc().
     * Memory allocated from heap at runtime.
     * Must be released using free().
     */
    char *str7 = malloc(20);

    strcpy(str7, "dynamic");

    printf("str7: %s\n", str7);

    free(str7);


    /* Method 8:
     * String creation using strcpy().
     * Copies source string into destination buffer.
     */
    char str8[20];

    strcpy(str8, "copied_string");

    printf("str8: %s\n", str8);


    /* Method 9:
     * Formatted string creation using snprintf().
     * Safely formats data into string buffer.
     */
    char str9[50];

    snprintf(str9,
             sizeof(str9),
             "Age=%d Score=%.1f",
             25,
             95.5);

    printf("str9: %s\n", str9);


    /* Method 10:
     * Array of strings (2D character array).
     * Stores multiple strings.
     */
    char names[3][20] =
    {
        "John",
        "Alice",
        "Bob"
    };

    printf("\nNames:\n");

    for(int i=0; i<3; i++)
    {
        printf("%s\n", names[i]);
    }


    /* Method 11:
     * Manual string input using getchar().
     * Reads input character-by-character.
     * Stops at newline.
     */
    char str10[50];
    char ch;
    int i = 0;

    printf("\nEnter str10 using getchar(): ");

    while((ch = getchar()) != '\n')
    {
        str10[i++] = ch;
    }

    str10[i] = '\0';

    printf("str10: %s\n", str10);


    return 0;
}
