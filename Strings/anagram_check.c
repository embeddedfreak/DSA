#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
Algorithm: Check whether two strings are anagrams

Step 1: Read two input strings.
Step 2: Compare their lengths.
         If lengths are different, print
         "Strings are not anagrams" and exit.
Step 3: Create a frequency array of size 26
         and initialize all elements to 0.
Step 4: Traverse the first string and increment
         the frequency of each character.
Step 5: Traverse the second string and decrement
         the frequency of each character.
Step 6: Traverse the frequency array.
         If any element is not equal to 0,
         the strings are not anagrams.
Step 7: If all elements are 0,
         the strings are anagrams.
Step 8: Print the result.
*/

int main()
{
        char str1[10], str2[10];

        // Assume strings are anagrams initially
        bool isAnagram = true;

        // Read first string
        printf("Enter string 1: \n");
        scanf("%s", str1);

        // Read second string
        printf("Enter string 2: \n");
        scanf("%s", str2);

        // Check if lengths are equal
        if(strlen(str1) != strlen(str2)) {
                printf("Strings are not anagrams\n");
                return 0;
        }

        // Frequency array for lowercase letters a-z
        int freq[26] = {0};

        // Increment frequency for characters in first string
        for(int i = 0; str1[i] != '\0'; i++) {
                freq[str1[i] - 'a']++;
        }

        // Decrement frequency for characters in second string
        for(int i = 0; str2[i] != '\0'; i++) {
                freq[str2[i] - 'a']--;
        }

        // Check whether all frequencies are zero
        for(int i = 0; i < 26; i++) {
                if(freq[i] != 0) {
                        isAnagram = false;
                        break;
                }
        }

        // Display result
        if(isAnagram) {
                printf("Strings are anagrams\n");
        } else {
                printf("Strings are not anagrams\n");
        }

        return 0;
}
