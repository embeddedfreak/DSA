#include <iostream>
#include <cmath>
using namespace std;


bool isAmstrong(int num)
{
	int dig = 0;
	int temp = num;
	int rem, tot = 0;

	while(temp!=0) {
		dig++;
		temp = temp / 10;	
	}

	temp = num;
	while(temp!=0) {
		rem = temp % 10;
		/* If you need without the pow 
		 * Then simply run loop from 0-dig
		 * And calculate product
		 * product = 1
		 * product = product * rem
		 */
		tot = tot + pow(rem, dig);
                temp = temp / 10;
        }

	if(tot == num)
		return true;


	return false;
}

int main()
{
	int num;
	cout<<"Enter a Number"<<endl;
	cin>>num;

	if(isAmstrong(num))
		cout<<"Number is Amstrong"<<endl;
	else
		cout<<"Number is not a Amstrong"<<endl;

	return 0;
}
