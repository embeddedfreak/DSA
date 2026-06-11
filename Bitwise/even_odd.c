#include <stdio.h>

int main()
{
    int num;

    printf("Enter a number:\n");
    scanf("%d", &num);

    if (num & 1)
    {
        printf("Number is odd\n");
    }
    else
    {
        printf("Number is even\n");
    }

    return 0;
}
