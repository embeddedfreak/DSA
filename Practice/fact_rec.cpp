#include <iostream>

using namespace std;

long long int factorial(int num)
{
	if(num < 0)
		return -1;

	if(num == 0 || num == 1) {
		return 1;
	}

	return num * factorial(num - 1);
}
int main()
{
	int num;
	cout<<"Enter a Number"<<endl;
	cin>>num;

	cout<<"Factorial of "<<num<<" is: "<<factorial(num)<<endl;
	return 0;
}
