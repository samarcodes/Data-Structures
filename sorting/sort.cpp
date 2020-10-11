#include<iostream>

using namespace std;

void BubbleSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		bool sorted = true;
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				sorted = false;
				swap(a[j], a[j + 1]);
			}
		}
		if (sorted) {
			break;
		}
	}
}

void InsertionSort(int a[], int n) {
	int i, j;
	for (i = 1; i < n; i++) {
		int temp = a[i];
		for (j = i - 1; j >= 0 && a[j] > temp; j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}
}

void SelectionSort(int a[], int n) {
	int min_index;
	for (int i = 0; i < n - 1; i++) {
		for (int j = min_index = i; j < n; j++) {
			if (a[j] < a[min_index]) {
				min_index =  j;
			}
		}
		swap(a[i], a[min_index]);
	}
}

int partition(int a[], int l, int h) {
	int pivot = a[l];
	int i = l;
	int j = h;

	while (i < j) {
		while (a[i] <= pivot) {
			i++;
		}
		while (a[j] > pivot) {
			j--;
		}
		if (i < j) {
			swap(a[i], a[j]);
		}
	}
	swap(a[l], a[j]);
	return j;
}

void QuickSort(int a[], int l, int h) {
	if (l >= h) {
		return;
	}

	int pivot = partition(a, l, h);

	QuickSort(a, l, pivot - 1);
	QuickSort(a, pivot + 1, h);
}

void Merge(int a[], int l, int mid, int h) {
	int i = l;
	int j = mid + 1;
	int k = l;

	int temp[h + 1];
	while (i <= mid && j <= h) {
		if (a[i] < a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
		}
	}
	while (i <= mid) {
		temp[k++] = a[i++];
	}
	while (j <= h) {
		temp[k++] = a[j++];
	}

	//copy back elements to array a
	for (int i = l; i <= h; i++) {
		a[i] = temp[i];
	}
}

//still needs improvements
void IMergeSort(int a[], int n) {
	int p, i, l, mid, h;
	for (p = 2; p <= n; p *= 2) {
		for (i = 0; i + p - 1 < n; i += p) {
			l = i;
			h = i + p - 1;
			mid = (l + h) / 2;
			Merge(a, l, mid, h);
		}
	}
	if (p / 2 < n) {
		Merge(a, 0, p / 2 - 1, n - 1);
	}
}

void RMergeSort(int a[], int l, int h) {
	if (l >= h) {
		return;
	}

	int mid = l + (h - l) / 2;

	RMergeSort(a, l, mid);
	RMergeSort(a, mid + 1, h);

	Merge(a, l, mid, h);
}

void display(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	int a[] = {5, 2, 4, 5, 3, 1, 4};
	int n = sizeof(a) / sizeof(a[0]);

	//BubbleSort(a, n);
	//InsertionSort(a, n);
	//SelectionSort(a, n);
	//QuickSort(a, 0, n - 1);
	IMergeSort(a, n);
	//RMergeSort(a, 0, n - 1);

	display(a, n);

	return 0;
}