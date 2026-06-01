#include <iostream>
#define COL_SIZE 3
#define ROW_SIZE 3

using namespace std;


int main()
{
	int arr[ROW_SIZE][COL_SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

	/* Row Sum */
	for(int i = 0; i < ROW_SIZE; i++) {
		int sum = 0;
		for(int j = 0; j < COL_SIZE; j++) {
			sum += arr[i][j];	
		}
		cout<<"Row "<<i<<" sum is: "<<sum<<endl;
	}

	/* Column Sum */
	for(int j = 0; j < COL_SIZE; j++) {
		int sum = 0;
		for(int i = 0; i < ROW_SIZE; i++) {
			sum += arr[i][j];	
		}
		cout<<"Column "<<j<<" sum is: "<<sum<<endl;
	}
	return 0;
}

