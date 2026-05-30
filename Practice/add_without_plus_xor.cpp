#include <iostream>

using namespace std;

int main()
{
	int a = 5, b = 3;


	int sum = 0, carry;

	while(b != 0) {
		sum = a ^ b;
		carry = (a & b) << 1;
		a = sum;
		b = carry;
	}
	cout<<sum<<endl;

	return 0;
}
