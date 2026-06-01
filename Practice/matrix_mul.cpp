#include <iostream>
#define ROW_SIZE 5
#define COL_SIZE 5

using namespace std;

int main()
{
	int a[ROW_SIZE][COL_SIZE], b[ROW_SIZE][COL_SIZE], res[ROW_SIZE][COL_SIZE];
	int a_r_size, a_c_size, b_r_size, b_c_size;
	cout<<"Enter array \"a\" row and column size"<<endl;
	cin>>a_r_size>>a_c_size;

	cout<<"Enter array \"a\" elements"<<endl;
	for(int i = 0; i < a_r_size; i++) {
		for(int j = 0; j < a_c_size; j++) {
			cin>>a[i][j];
		}
	}

	cout<<"Enter array \"b\" row and column size"<<endl;
	cin>>b_r_size>>b_c_size;

	cout<<"Enter array \"b\" elements"<<endl;
	for(int i = 0; i < b_r_size; i++) {
		for(int j = 0; j < b_c_size; j++) {
			cin>>b[i][j];
		}
	}

#if 0

Loop 1: (i) I am selecting a row from A.

Loop 2: (j) I am selecting a col from A.

Row of A:      1   2   3
                ↑   ↑   ↑
                k   k   k

Column of B:   7
               9
               11
               ↑
               k


#endif

	if(a_c_size == b_r_size) {
		for(int i = 0; i < a_r_size; i++) {
			for(int j = 0; j < b_c_size; j++) {
					res[i][j] = 0;
				for(int k = 0; k < a_c_size; k++) {
					res[i][j] += a[i][k] * b[k][j];		
				}
			}
		}


		cout<<"Resultant Matrix is : "<<endl;

		for(int i = 0; i < a_r_size; i++) {
                	for(int j = 0; j < b_c_size; j++) {
                        	cout<<res[i][j]<<" ";
			}
			cout<<endl;
                }

	} else {
		cout<<"Matrix multiplication not possible"<<endl;
	}

	return 0;
}
