#include<iostream>
#define SIZE 10
using namespace std;

int first_hash_function(int key) {
	return key % 10;
}
int second_hash_function(int key) {
	return 7 - (key % 7);
}

int double_hash_function(int HT[], int key) {
	int index = first_hash_function(key);
	if (HT[index] == 0) {
		return index;
	}
	else {
		int i = 0;
		while (HT[(index + i * second_hash_function(key)) % SIZE] != 0) {
			i++;
		}
		return (index + i * second_hash_function(key)) % SIZE;
	}
}

void Insert(int HT[], int key) {
	int index = double_hash_function(HT, key);
	HT[index] = key;
}

int main() {
	int HT[SIZE] = {0};

	Insert(HT, 5);
	Insert(HT, 15);
	Insert(HT, 25);
	Insert(HT, 35);
	Insert(HT, 95);

	for (int i = 0; i < SIZE; i++) {
		cout << HT[i] << " ";
	}
	cout << endl;

	return 0;
}