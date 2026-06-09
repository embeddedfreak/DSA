#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
Algorithm:
1. Read a string from the user.
2. Find its length n.
3. Initialize maxLen = 0 to store the result.
4. Try all possible prefix lengths from 1 to n-1.
5. For each length 'len':
      a. Assume prefix and suffix match (match = true).
      b. Compare prefix (str[0...len-1]) with suffix (str[n-len...n-1]).
      c. If any character mismatches, set match = false and break.
6. If prefix and suffix match for a given length:
      - Update maxLen = len.
7. After checking all lengths, print maxLen as the longest prefix-suffix length.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

int main()
{
        char str[100];

        /* Input string */
        printf("Enter a string\n");
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';

        int n = strlen(str);

        int maxLen = 0;

        /* Try all possible prefix lengths */
        for(int len = 1; len < n; len++) {

                bool match = true;

                /* Compare prefix and suffix for current length */
                for(int i = 0; i < len; i++) {

                        /* Check if characters at prefix and suffix positions match */
                        if(str[i] != str[n - len + i]) {
                                match = false;   // mismatch found
                                break;           // stop checking this length
                        }
                }

                /* If prefix and suffix match, update answer */
                if(match) {
                        maxLen = len;
                }
        }

        /* Output result */
        printf("Longest Prefix-Suffix length = %d\n", maxLen);

        return 0;
}
