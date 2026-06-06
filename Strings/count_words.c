#include <stdio.h>
#include <string.h>
#include <ctype.h>
/* Algorithm:
 * 1. Read the input string from the user.
 * 2. Remove the trailing newline character (if present).
 * 3. Initialize:
 *      - w_count = 0 (stores number of words)
 *      - first_let = 1 (indicates start of a new word)
 * 4. Traverse the string character by character.
 * 5. If the current character is a whitespace:
 *      - Set first_let = 1.
 *      - This indicates the next non-space character
 *        will be the beginning of a new word.
 * 6. Otherwise, if first_let is 1:
 *      - Increment w_count.
 *      - Set first_let = 0 to avoid counting
 *        the remaining characters of the same word.
 * 7. Continue until the end of the string.
 * 8. Display the total word count.
 */

int main()
{
	char  str[10];
	printf("Enter a String\n");
	// Read the input string
	fgets(str, sizeof(str), stdin);

	// Remove trailing newline
	str[strcspn(str, "\n")] = '\0';

	// Assume the next non-space character starts a word
	int w_count = 0;
	int first_let = 1;

	// Traverse the string
	for (int i = 0; str[i] != '\0'; i++) {

		// Space found: next non-space character starts a new word
		if (isspace((unsigned char)str[i])) {
			first_let = 1;
		}

		// First character of a new word
		else if (first_let) {
			w_count++;
			first_let = 0;
		}
	}

	// Display total number of words
	printf("Total Word count = %d\n", w_count);
	return 0;
}

