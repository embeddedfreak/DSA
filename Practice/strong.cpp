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

bool strong_num(int num)
{
	int temp = num;
	int rem, total = 0;

	while(temp != 0) {
		rem = temp % 10;
		total += factorial(rem);
		temp = temp / 10;
	}

	if(num == total) {
		return true;
	}
	return false;
}
int main()
{
	int num;
	cout<<"Enter a Number"<<endl;
	cin>>num;


	if(strong_num(num)) {
		cout<<"Num is strong"<<endl;
	} else {
		cout<<"Num not is strong"<<endl;
	}
	return 0;
}
