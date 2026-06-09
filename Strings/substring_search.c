#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
Algorithm:
1. Read the main string (str) from the user.
2. Read the substring (sub) from the user.
3. Find lengths of both strings: n = strlen(str), m = strlen(sub).
4. Slide a window of size m over the main string from index 0 to n - m.
5. For each position i:
      - Assume the substring matches (set match = true).
      - Compare each character of sub with str[i + j].
      - If any mismatch occurs, set match = false and break.
6. If match remains true:
      - Print the index i where substring is found.
      - Mark found = 1.
7. After full traversal, if found is still 0:
      - Print "No Match found".
8. End program.

Time Complexity: O(n * m)
Space Complexity: O(1)
*/

int main()
{
        char str[100];
        char sub[10];

        /* Input main string */
        printf("Enter a string\n");
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';

        /* Input substring */
        printf("Enter a substring\n");
        fgets(sub, sizeof(sub), stdin);
        sub[strcspn(sub, "\n")] = '\0';

        int n = strlen(str);
        int m = strlen(sub);

        int found = 0;

        /* Sliding window over main string */
        for(int i = 0; i <= n - m; i++) {

                bool match = true;

                /* Compare substring with current window */
                for(int j = 0; j < m; j++) {

                        if(sub[j] != str[i + j]) {
                                match = false;   // mismatch found
                                break;           // stop checking this window
                        }
                }

                /* If full match found */
                if(match) {
                        printf("Match found at index %d\n", i);
                        found = 1;
                }
        }

        /* If no match found in entire string */
        if(!found) {
                printf("No Match found\n");
        }

        return 0;
}
