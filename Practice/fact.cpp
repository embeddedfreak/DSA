#include <iostream>

using namespace std;

int factorial(int num)
{
	int fact = 1;
	for(int i = num; i >=1; i--) {
		fact = fact * i;
	}
	return fact;
}
int main()
{
	int num;
	cout<<"Enter a Number"<<endl;
	cin>>num;

	cout<<"Factorial of "<<num<<" is: "<<factorial(num)<<endl;
	return 0;
}
