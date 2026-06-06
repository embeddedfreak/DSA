#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Count {
    int vow_count;
    int cons_count;
    int digit_count;
    int space_count;
};

int main(void)
{
    char str[100];
    struct Count c = {0};

    printf("Enter a String\n");

    if (fgets(str, sizeof(str), stdin) == NULL)
        return 1;

    str[strcspn(str, "\n")] = '\0';

    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = str[i];

        if (isdigit(ch)) {
            c.digit_count++;
        }
        else if (ch == ' ') {
            c.space_count++;
        }
        else if (isalpha(ch)) {
            switch (tolower(ch)) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    c.vow_count++;
                    break;
                default:
                    c.cons_count++;
            }
        }
    }

    printf("%d %d %d %d\n",
           c.vow_count,
           c.cons_count,
           c.digit_count,
           c.space_count);

    return 0;
}
