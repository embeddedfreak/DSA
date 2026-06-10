#include <stdio.h>

/*
 * Algorithm: Sliding Window Sum of Size 3
 *
 * Step 1: Initialize the input array.
 * Step 2: Find the size of the array.
 * Step 3: Set the window size (w_size = 3).
 * Step 4: Calculate the sum of the first window.
 * Step 5: Print the sum of the first window.
 * Step 6: Slide the window one element at a time:
 *          - Add the new element entering the window.
 *          - Subtract the element leaving the window.
 * Step 7: Print the sum of each new window.
 * Step 8: Repeat until the end of the array is reached.
 * Step 9: Exit the program.
 */

int main()
{
        // Input array
        int arr[6] = {1, 2, 3, 4, 5, 6};

        // Calculate the number of elements in the array
        int arr_size = sizeof(arr)/sizeof(arr[0]);

        // Define the sliding window size
        int w_size = 3;

        // Variable to store the current window sum
        int sum = 0;

        // Calculate the sum of the first window
        for(int i = 0; i < w_size; i++) {
                sum += arr[i];
        }

        // Print the sum of the first window
        printf("Sum = %d\n", sum);

        // Slide the window through the array
        for(int i = w_size; i < arr_size; i++) {

                // Add the new element and remove the old element
                sum += arr[i] - arr[i-w_size];

                // Print the current window sum
                printf("Sum = %d\n", sum);
        }

        return 0;
}
