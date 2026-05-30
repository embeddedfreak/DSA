#include <iostream>

using namespace std;

int main()
{
	int a = -5, b = -10;

	if(b > 0) {
		while(b != 0) {
			++a;
			--b;
		}
	} else {
		while(b != 0) {
			--a;
			++b;
		}
	}

	cout<<a<<endl;

	return 0;
}
