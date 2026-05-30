#include <iostream>

using namespace std;


bool prime(int num)
{
	if(num < 2)
		return false;

	for(int i = 2; i*i <= num; i++) {
		if(num % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int num;
	cout<<"Enter a Number"<<endl;
	cin>>num;

	if(prime(num)) {
		cout<<"Number is prime"<<endl;
	} else {
		cout<<"Number is not a prime"<<endl;
	}
	return 0;
}
