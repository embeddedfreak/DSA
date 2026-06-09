/*
Algorithm:
1. Read the input string from the user.
2. Create a frequency array of size 26 and initialize all elements to 0.
3. Traverse the string and count the occurrences of each character:
      freq[str[i] - 'a']++
4. Traverse the string again from left to right.
5. For each character, check its frequency in the frequency array.
6. If the frequency is 1:
      - It is the first non-repeating character.
      - Print the character and terminate the program.
7. If no character with frequency 1 is found after the traversal,
   print "No Non repeating character".
8. End the program.

Time Complexity: O(n)
Space Complexity: O(1)  // Fixed-size frequency array (26)
*/

#include <stdio.h>
#include <string.h>

int main()
{
        char str[10];
        int freq[26] = {0};

        /* Read input string from user */
        printf("Enter a string\n");
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';

        /* Count frequency of each character */
        for(int i = 0; str[i] != '\0'; i++) {
                freq[str[i] - 'a']++;
        }

        /* Find the first character whose frequency is 1 */
        for(int i = 0; str[i] != '\0'; i++) {
                if(freq[str[i] - 'a'] == 1) {
                        printf("First Non repeating character is %c\n", str[i]);
                        return 0;
                }
        }

        /* No unique character found */
        printf("No Non repeating character\n");

        return 0;
}
