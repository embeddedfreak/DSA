#include <iostream>

using namespace std;

int main()
{
	int year = 2012;

	if((year % 400) == 0) {
		cout<<"Year is Leap Year"<<endl;
	} else if((year % 100) == 0) {
                cout<<"Year is not a Leap Year"<<endl;
        } else if ((year % 4) == 0) {
                cout<<"Year is Leap Year"<<endl;
        } else {
		cout<<"Year is  not a Leap Year"<<endl;
	}
	return 0;
}
