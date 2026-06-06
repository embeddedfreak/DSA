/*
 * Algorithm:
 * 1. Read the input sentence from the user.
 * 2. Remove the trailing newline character added by fgets().
 * 3. Traverse the string to identify each word.
 * 4. When a space or end of string is encountered:
 *      a. Mark the end of the current word.
 *      b. Reverse the word in place.
 *      c. Move to the beginning of the next word.
 * 5. Repeat until all words are processed.
 * 6. Print the string with each word reversed.
 *
 * Example:
 * Input  : "Hello World"
 * Output : "olleH dlroW"
 */

#include <stdio.h>
#include <string.h>

/* Function to reverse characters between start and end indices */
void reverse(char str[], int start, int end)
{
    char temp;  // Temporary variable for swapping

    printf("Reversing start = %d, end = %d\n", start, end);

    /* Swap characters from both ends until the middle is reached */
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

int main()
{
    char str[100];  // Buffer to store the input string

    printf("Enter a sentence to reverse the words\n");

    /* Read a line of input */
    fgets(str, sizeof(str), stdin);

    /* Remove trailing newline character, if present */
    str[strcspn(str, "\n")] = '\0';

    int start = 0;  // Starting index of the current word
    int end;        // Ending index of the current word

    /* Traverse the string */
    for (int i = 0; ; i++) {

        /* Word boundary found (space or end of string) */
        if (str[i] == ' ' || str[i] == '\0') {

            /* Last character of the current word */
            end = i - 1;

            /* Reverse the current word */
            reverse(str, start, end);

            /* Move start to the next character after the space */
            start = i + 1;
        }

        /* Stop when end of string is reached */
        if (str[i] == '\0') {
            break;
        }
    }

    /* Display the final string */
    printf("String after reversing is: %s\n", str);

    return 0;  // Indicate successful program termination
}
