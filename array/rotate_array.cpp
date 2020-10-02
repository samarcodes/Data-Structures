#include<iostream>

using namespace std;

//using temp array
//time : O(n)
//space : O(d)
void rotate1(int a[], int n, int rotation_factor) {
	int temp[rotation_factor];
	int i;

	for (i = 0; i < rotation_factor; i++) {
		temp[i] = a[i];
	}

	for (i = rotation_factor; i < n; i++) {
		a[i - rotation_factor] = a[i];
	}

	int j = 0;
	for (i = n - rotation_factor; i < n; i++) {
		a[i] = temp[j++];
	}
}

//rotating n times
//time : O(n*d)
//space : O(1)
void rotateleft(int arr[], int n) {
	int temp = arr[0];
	int i;
	for (i = 1; i < n; i++) {
		arr[i - 1] = arr[i];
	}
	arr[i - 1] = temp;
}

void rotate2(int arr[], int n, int rotation_factor) {
	for (int i = 0; i < rotation_factor; i++) {
		rotateleft(arr, n);
	}
}

//juggling algorithm
//time : O(n)
//space : O(1)
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

void rotate3(int arr[], int n, int rotation_factor) {
	rotation_factor %= n;
	if (rotation_factor == 0)
		return;

	int g_c_d = gcd(n, rotation_factor);
	int i;
	for (i = 0; i < g_c_d; i++) {
		int temp = arr[i];
		int j = i;
		while (1) {
			int d = j + rotation_factor;

			if (d >= n) {
				d = n - d;
			}
			//this statement is always after the first if statement
			//coz if d>=n(10 elements 12 index) then we have to make
			//it 12-10=2 first
			if (d == i)
				break;

			arr[j] = arr[d];
			j = d;
		}
		arr[j] = temp;
	}
}

int main() {
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n = sizeof(arr) / sizeof(arr[0]);

	//rotate1(arr, n, 2);
	//rotate2(arr, n, 3);
	rotate3(arr, n, 5);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}