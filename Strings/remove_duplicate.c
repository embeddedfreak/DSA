#include <stdio.h>
#include <string.h>

/*
Algorithm: Remove Duplicate Characters from a String (In-Place)

Step 1: Read the input string.
Step 2: Traverse the string using index i.
Step 3: For each character str[i], compare it with all previous characters (0 to i-1).
Step 4: If a duplicate is found:
        - Shift all characters left from position i.
        - Reduce the string size logically.
        - Decrement i to recheck the new character at position i.
Step 5: Continue until end of string is reached.
Step 6: Print the final string without duplicates.
*/

int main()
{
        char str[10];   // Input string (note: small size)

        printf("Enter a string:\n");
        scanf("%s", str);   // Read input string (no spaces allowed)

        int dup_idx =  -1;  // (not used, but kept as in original code)

        // Traverse string starting from index 1
        for(int i = 1; str[i] != '\0'; i++) {

                // Check previous characters for duplicates
                for(int j = 0; j < i; j++) {

                        if(str[i] == str[j]) {

                                // If duplicate found, shift characters left
                                for(int k = i; str[k] != '\0'; k++) {
                                        str[k] = str[k+1];
                                }

                                // Move back to recheck new character at position i
                                i--;
                                break;
                        }
                }
        }

        // Print final string after removing duplicates
        printf("String after duplicate removal is: %s\n", str);

        return 0;
}
