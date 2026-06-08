#include <stdio.h>
#include <string.h>

/*
Algorithm: Find Frequency of Characters (ASCII Order)

Step 1: Read input string using fgets.
Step 2: Remove newline character if present.
Step 3: Create a frequency array of size 256 and initialize to 0.
Step 4: Traverse the string and increment frequency using ASCII value of each character.
Step 5: Traverse the frequency array from 0 to 255.
Step 6: If frequency > 0, print the character and its count.
Step 7: End program.
*/

int main()
{
        char str[20];

        // Frequency array for all ASCII characters
        int freq[256] = {0};

        // Input string
        printf("Enter a string: \n");
        fgets(str, sizeof(str), stdin);

        // Remove newline character
        str[strcspn(str, "\n")] = '\0';

        // Count frequency of each character (ASCII mapping)
        for(int i = 0; str[i] != '\0'; i++) {
                freq[(unsigned char)str[i]]++;
        }

        // Print frequency in ASCII order
        for(int i = 0; i < 256; i++) {
                if(freq[i] > 0) {
                        printf("%c -> %d\n", i , freq[i]);
                }
        }

        return 0;
}
