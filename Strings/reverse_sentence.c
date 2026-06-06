/*
 * Algorithm:
 * 1. Read the input sentence from the user.
 * 2. Remove the trailing newline character added by fgets().
 * 3. Reverse the entire string.
 * 4. Traverse the reversed string to identify each word.
 * 5. Whenever a space or end of string is encountered:
 *      a. Mark the end of the current word.
 *      b. Reverse that word.
 *      c. Move to the beginning of the next word.
 * 6. After reversing each word, the words appear in reverse order
 *    while their characters remain in the correct order.
 * 7. Print the final reversed sentence.
 *
 * Example:
 * Input  : "Hello World Program"
 * Step 1 : "margorP dlroW olleH"   (reverse entire string)
 * Step 2 : "Program World Hello"  (reverse each word)
 * Output : "Program World Hello"
 */

#include <stdio.h>
#include <string.h>

/* Function to reverse characters between start and end indices */
void reverse(char str[], int start, int end)
{
    char temp;  // Temporary variable for swapping

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
    char str[100];  // Buffer to store input string

    printf("Enter a string\n");

    /* Read a line of input from the user */
    fgets(str, sizeof(str), stdin);

    /* Remove trailing newline character if present */
    str[strcspn(str, "\n")] = '\0';

    /* Reverse the complete string */
    reverse(str, 0, strlen(str) - 1);

    int start = 0;  // Starting index of the current word
    int end;        // Ending index of the current word

    /* Traverse the reversed string */
    for (int i = 0; ; i++) {

        /* Word boundary found */
        if (str[i] == ' ' || str[i] == '\0') {

            /* Last character of the current word */
            end = i - 1;

            /* Reverse the current word */
            reverse(str, start, end);

            /* Move to the start of the next word */
            start = i + 1;
        }

        /* Exit loop when end of string is reached */
        if (str[i] == '\0') {
            break;
        }
    }

    /* Display the sentence with word order reversed */
    printf("Entered string after complete reverse is : %s\n", str);

    return 0;  // Successful program termination
}
