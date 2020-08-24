#include<iostream>

using namespace std;

struct Node {
	int data;
	struct Node *next;
};

class stack {
	Node *head;
	int size;
public:
	stack(): head(NULL), size(0)
	{
	}
	void push(int value);
	void pop();
	int top();
	bool isEmpty();
	bool isFULL();
	void show();
};

void stack:: push(int value) {
	Node *new_node = new Node;
	new_node->data = value;
	new_node->next = NULL;
	if (!head) {
		head = new_node;
	}
	else {
		new_node->next = head;
		head = new_node;
	}
	size += 1;
}

void stack:: pop() {
	if (head) {
		Node *temp = head;
		head = head->next;
		delete temp;
	}
}

int stack:: top() {
	if (head)
		return head->data;
	else
		return -1;
}

void stack:: show() {
	Node *temp = head;
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
	cout << "size : " << size << endl;
}

bool stack:: isEmpty() {
	bool ans = head ? false : true;
	return ans;
}

bool stack:: isFULL() {

}

int main() {
	stack st;
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);

	st.show();

	return 0;
}