#include<iostream>

using namespace std;

template<class T>
class Node {
public:
	T data;
	Node *next;
};

template<class T>
class stack {
	Node<T> *head;
	int _size;
public:
	stack(): head(NULL), _size(0) //default ctor
	{
	}
	void push(T value);
	void pop();
	T top();
	int size();
	bool isEmpty();
	void show();
	~stack()  //destructor
	{
		Node<T> *temp = head;
		while (temp) {
			head = head->next;
			delete temp;
			temp = head;
		}
	}
};

template<class T>
void stack<T>:: push(T value) {
	Node<T> *new_node = new Node<T>;
	new_node->data = value;
	new_node->next = NULL;
	if (!head) {
		head = new_node;
	}
	else {
		new_node->next = head;
		head = new_node;
	}
	_size += 1;
}

template <class T>
void stack<T>:: pop() {
	if (head) {
		Node<T> *temp = head;
		head = head->next;
		delete temp;
	}
}

template <class T>
T stack<T>:: top() {
	if (head)
		return head->data;
	else
		return 0;
}

template <class T>
int stack<T>:: size() {
	cout << _size << endl;
}

template <class T>
void stack<T>:: show() {
	Node<T> *temp = head;
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

template <class T>
bool stack<T>:: isEmpty() {
	bool ans = head ? false : true;
	return ans;
}

int main() {
	stack<char> st;
	st.push('a');
	st.push('b');
	st.push('c');
	st.push('d');
	st.push('e');
	st.push('f');

	st.show();
	st.size();

	return 0;
}