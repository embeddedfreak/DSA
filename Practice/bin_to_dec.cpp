#include <iostream>

using namespace std;

int main()
{
	int bin = 1001;

	int bit;
	int weight = 1;
	int decimal = 0;
	while(bin != 0) {
		bit = bin % 10;
		decimal	= decimal + (bit * weight);
		weight = weight * 2;
		bin = bin / 10;
	}

	cout<<decimal<<endl;
	return 0;
}
