/*
Problem: Fast Exponentiation (Binary Exponentiation)

Algorithm:
1. Take base and exponent as input.
2. Handle negative exponent:
   - If exponent is negative, invert the base (1/base).
   - Work with absolute value of exponent.
3. Initialize result as 1.
4. While exponent is greater than 0:
   - If current exponent bit is 1 (odd), multiply result with base.
   - Square the base for next bit.
   - Divide exponent by 2.
5. Final result contains base^exp.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <iostream>

using namespace std;

int main()
{
        int base = 3;
//      int exp = 5;
        int exp = -5;

        int binform = abs(exp);

        double b;

        if(exp < 0)
                b = 1.0/base;
        else
                b = base;

        double ans = 1.0;
        while(binform) {
                if(binform % 2) {
                        ans *= b;
                }
                b *= b;
                binform/=2;
        }

        cout<<"base^exp: "<< ans<<endl;
        return 0;
}
