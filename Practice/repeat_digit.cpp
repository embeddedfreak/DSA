#include <iostream>

using namespace std;

bool repeat_check(int num)
{
	int dig;
	int arr[10] = {0};
	while(num != 0) {
		dig = num % 10;
		if(arr[dig] == 1) {
			return true;
		}
		arr[dig]++;
		num = num / 10;
	}
	
	return false;
}
int main() 
{
	int num;
	cout<<"Enter a number"<<endl;
	cin>>num;

	if(repeat_check(num)) {
		cout<<"There is repeated digit in this number"<<endl;
	} else {
		cout<<"No repeated digits in this number"<<endl;	
	}
	return 0;
}
