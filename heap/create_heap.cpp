#include<iostream>

using namespace std;

void insert(int a[], int n) {
	int temp = a[n];
	int i = n;
	while (temp > a[i / 2] && i > 1) {
		a[i] = a[i / 2];
		i /= 2;
	}
	a[i] = temp;
}

void createHeap(int a[], int n) {
	for (int i = 2; i < n; i++) {
		insert(a, i);
	}
}

void heapify(int a[], int n) {
	for (int i = n / 2; i > 0; i--) {
		int j = 2 * i ;
		int k = i;
		while (j < n) {
			//compare left and right children of current i
			if (a[j + 1] > a[j]) {
				j += 1;
			}
			if (a[k] < a[j]) {
				swap(a[k], a[j]);
				k = j;
				j *= 2;
			}
			else {
				break;
			}
		}
	}
}

void deleteHeap(int a[], int n) {
	int x = a[1];
	int i = 1;
	int j = 2 * i;

	a[i] = a[n - 1];

	while (j < n - 1) {
		if (a[j + 1] > a[j]) {
			j = j + 1;
		}
		if (a[i] < a[j]) {
			swap(a[i], a[j]);
			i = j;
			j = 2 * j;
		}
		else {
			break;
		}
	}
	a[n - 1] = x;
}

void showHeap(int a[], int n) {
	for (int i = 1; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	int a[] = {0, 10, 20, 30, 5, 40, 50};
	int n = sizeof(a) / sizeof(int);

	heapify(a, n);

	for (int i = 0; i < n - 1; i++)
		deleteHeap(a, n - i);

	showHeap(a, n);
	return 0;
}