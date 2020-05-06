#include <iostream>
#include <string.h>
#define  N1  5
#define  N2  10
#define  N3  7
using namespace std;


class MYARRAY {
	double*arr3;

public:

	MYARRAY() {
		arr3 = new double[N3];
		for (int i = 0; i < N3; i++) {
			 arr3[i] = i+1.;
		}
	}

	void printarr() {
		cout << "\nThird container: [";
		for (int i = 0; i < N3-1; i++) {
			cout << arr3[i]  << ", ";
		}
		cout << arr3[N3-1] << "]\n";
	}

	double* getaarr() {
		return arr3;
	}

}; 


template <class T>
void print(T arr1[], T arr2[], int n) {
	int j, j2, t, t2, p=0;
	
	for (int i = 0; i < (N2 - n + 1); i++) {

		if (arr1[0] == arr2[i]) {
			j = i;
			t = i;

			for (int k = 0; k < n && j < N2; k++, j++) {

				if (!(arr1[k] == arr2[j])) {
					break;
				}
			}

			if (j - i == n) {
				t2 = t;
				j2 = j-1;
				p = 1;
			}
		}
	}

	if (p) {
		cout << "Last entry from " << t2 << " to " << j2 << " number." << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return;
}


int main() {
	double arr1[N1], n;
	double arr2[N2];
	MYARRAY arr3;

	for (int i = 0; i < N1; i++) {
		cout << "Enter a[" << i << "]: ";
		cin >> arr1[i];
	}

	cout << "\n";

	for (int i = 0; i < N2; i++) {
		cout << "Enter a[" << i << "]: ";
		cin >> arr2[i];
	}

	cout << "\nFirst container: [";

	for (int i = 0; i < N1-1; i++) {
		cout << arr1[i] << ", ";
	}

	cout << arr1[N1-1] << "]\n\nSecont container: [";

	for (int i = 0; i < N2 - 1; i++) {
		cout << arr2[i] << ", ";
	}

	cout << arr2[N2 - 1] << "]\n";
	arr3.printarr();
	cout << "\nEnter N(the number of first elements in the first container), N <= " << N1 << endl;
	cin >> n;

	cout << "\nFor first container:" << endl;
	print(arr1, arr2, n);
	cout << "\nFor third container:" << endl;
	print(arr3.getaarr(), arr2, n);

	return 0;
}
