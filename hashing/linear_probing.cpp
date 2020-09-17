#include<iostream>
#define SIZE 10

using namespace std;

int hash_function(int key) {
	return key % 10;
}

int linear_probe(int HT[], int key) {
	int index = hash_function(key);
	int i = 0;
	while (HT[(index + i) % SIZE] != 0) {
		i++;
	}
	return (index + i) % SIZE;
}

void Insert(int HT[], int key) {
	int index = linear_probe(HT, key);
	HT[index] = key;
}

int Search(int HT[], int key) {
	int index = hash_function(key);

	int i = 0;
	while (HT[(index + i) % SIZE] != key) {
		if (HT[(index + i) % SIZE] == 0) {
			return -1;
		}
		i++;
	}

	return (index + i) % SIZE;
}

int main() {
	int HT[SIZE] = {0};

	Insert(HT, 12);
	Insert(HT, 25);
	Insert(HT, 35);
	Insert(HT, 26);

	for (int i = 0; i < SIZE; i++) {
		cout << HT[i] << " ";
	}
	cout << endl;

	cout << Search(HT, 105) << endl;

	return 0;
}