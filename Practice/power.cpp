#include <iostream>

using namespace std;

int main()
{
	int base = 2, exp = 3;

	int val = 1;
	for(int i = 1; i <= exp; i++) {
		val = val * base;
	}

	cout<<val<<endl;
	return 0;
}
