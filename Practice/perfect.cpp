#include <iostream>

using namespace std;

int main()
{
	int num = 496;
	int result = 0;

	for(int i = 1; i < num; i++ ){
		if((num % i) == 0) {
			result += i;	
		}
	}
	if(num == result) {
		cout<<"NUmber is perfect"<<endl;
	} else {
		cout<<"Number is not perfect"<<endl;
	}
}
