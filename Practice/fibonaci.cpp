#include <iostream>

using namespace std;

void fibonacii(int n)
{
	if(n < 0) {
		cout<<"N term enterned should be > 0"<<endl;
		return;
	}
	int a = 0, b = 1;
	int next = 0;

	for(int i = 1; i <= n; i++) {
		cout<<a<<" ";
		next = a + b;
		a = b;
		b = next;
	}
	cout<<endl;
}
int main()
{
	int n;
	cout<<"Enter N term to print finbonacii series"<<endl;
	cin>>n;

	fibonacii(n);
	return 0;
}
