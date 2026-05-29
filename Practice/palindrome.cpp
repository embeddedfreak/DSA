/* Write a C program to check whether a given number is a palindrome or not. */

#include <iostream>
#include <cmath>
using namespace std;

bool prime(int num) 
{
	if(num <= 1)
		return false;

	int div = ceil(sqrt(num));

	for(int i = 2; i <= div; i++)
	{
		if((num % i) == 0) {
			return false;
		}

	}
	return true;
}

int main()
{
	int num;

	cout<<"Enter a number"<<endl;
	cin>>num;

	if(prime(num)) {
		cout<<"Number is Palindrome"<<endl;
	} else {
		cout<<"Number is not a Palindrome"<<endl;
	}

	return 1;
}

#if 0

Optimised without using cmath and sqrt()

bool prime(int num)
{
    if(num <= 1)
        return false;

    for(int i = 2; i * i <= num; i++)
    {
        if(num % i == 0)
            return false;
    }

    return true;
}

#endif
