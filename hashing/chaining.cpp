#include<iostream>

using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

void SortedInsert(Node **head_ref, int data) {
	Node *new_node;
	new_node->data = data;
	new_node->next = NULL;

	if ((*head_ref) == NULL) {
		(*head_ref) = new_node;
		cout << "first" << endl;
	}
	else {
		Node *tail;
		Node *p = *head_ref;
		while (p && p->data < data) {
			tail = p;
			p = p->next;
		}
		if (p == (*head_ref)) {
			new_node->next = p;
			(*head_ref) = new_node;
			cout << "second" << endl;
		}
		else {
			new_node->next = p;
			tail->next = new_node;
			cout << "third" << endl;
		}
	}
}

int h(int key) {
	return key % 10;
}

void Insert(Node *hash[], int key) {
	int index = h(key);
	SortedInsert(&hash[index], index);
}

void show(Node *p) {
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
}

int main() {
	Node *head = NULL;
	SortedInsert(&head, 1);
	SortedInsert(&head, 5);
	SortedInsert(&head, 4);
	SortedInsert(&head, 3);
	SortedInsert(&head, 2);

	show(head);
	return 0;
}