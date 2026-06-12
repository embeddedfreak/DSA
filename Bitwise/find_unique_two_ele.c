/* 
 * Write a C program to find two non-repeating elements in an array
 * where every other element appears exactly twice.
 * Example:
 * Input:
 * 1 2 3 2 1 5
 * Output:
 * 3 5
 */
#include <stdio.h>

/*
    Algorithm:

    Step 1: XOR all elements of the array.
            This gives xor_all = x ^ y
            (where x and y are the two unique numbers)

    Step 2: Find a set bit in xor_all.
            We take the rightmost set bit using:
            mask = xor_all & (-xor_all)

            This bit is different between x and y.

    Step 3: Divide array elements into two groups:
            Group 1: elements where (arr[i] & mask) != 0
            Group 2: elements where (arr[i] & mask) == 0

    Step 4: XOR elements of each group separately.
            Duplicates cancel out automatically.

    Step 5: Remaining values in x and y are the two unique numbers.
*/

void findTwoUnique(int arr[], int n, int *x, int *y)
{
    int xor_all = 0;

    // Step 1: XOR all elements to get xor_all = x ^ y
    for(int i = 0; i < n; i++) {
        xor_all ^= arr[i];
    }

    // Step 2: Find rightmost set bit (differentiating bit between x and y)
    int mask = xor_all & (-xor_all);

    // Step 3: Initialize result containers (IMPORTANT logically)
    // (no change in logic, just clarity in understanding)
    *x = 0;
    *y = 0;

    // Step 4: Split elements into two groups based on mask
    for(int i = 0; i < n; i++) {

        if(arr[i] & mask) {
            // This group contains one unique number + its duplicates
            *x ^= arr[i];
        }
        else {
            // This group contains the other unique number + its duplicates
            *y ^= arr[i];
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 2, 1, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    int x = 0, y = 0;

    findTwoUnique(arr, n, &x, &y);

    printf("Two unique numbers are %d, %d\n", x, y);

    return 0;
}
