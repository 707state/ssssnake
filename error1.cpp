#include<iostream>
using namespace std;
void main() {
	const int n = 100;
	int arr[n];
	int a=0,  c=1;
	float b;
	for (int i = 0; i < n; i += 1) {
		cin >> arr[i];
		if (arr[i] == -1) {
			break;
		}
	}
	for (int i = 0; i < n; i += 1) {
		a =a+ arr[i];
		c =c* arr[i];
		b = a*10.0 / n;
	}
	
	int max, min;
	max = arr[0];
	min = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}
		cout << "Sum is " << a << endl;
		cout << "Average is " << b << endl;
		cout << "Product is " << c << endl;
		cout << "Smallest is " << min<<endl;
		cout << "Largest is " << max;
	
	return ;
}