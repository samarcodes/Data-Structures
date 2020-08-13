//by dividing into two lists
//reversing second list
//comparing lists
//reversing scend half again to get original LL
#include<iostream>
#include<climits>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

Node * create(int a[], int n) {
	Node *root, *new_node, *last;
	root = new Node;
	root->data = a[0];
	root->next = NULL;
	last = root;

	for (int i = 1; i < n; i++) {
		new_node = new Node;
		new_node->data = a[i];
		new_node->next = NULL;
		last->next = new_node;
		last = new_node;
	}

	return root;
}

void display(Node *p) {
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void reverse(Node **head_ref) {
	Node *current = *head_ref;
	Node *next = NULL;
	Node *prev = NULL;

	while (current) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

bool compareLists(Node *head1, Node *head2) {
	Node *temp1 = head1;
	Node *temp2 = head2;
	while (temp1 && temp2) {
		if (temp1->data != temp2->data) {
			return false;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	if (temp1 == NULL && temp2 == NULL)
		return true;

	//return false;
}

bool isPalindrome(Node *head) {
	if (!head->next) {
		return true;
	}

	Node *fast = head;
	Node *slow = head;
	Node *prev_of_slow = head;
	Node *mid = NULL;
	Node *second_half = NULL;
	bool result = true;

	while (fast && fast->next) {
		fast = fast->next->next;
		prev_of_slow = slow;
		slow = slow->next;
	}

	if (fast) {
		mid = slow;
		slow = slow->next;
	}

	second_half = slow;
	prev_of_slow->next = NULL;

	reverse(&second_half);

	result = compareLists(head, second_half);

	reverse(&second_half);

	if (mid) {
		prev_of_slow->next = mid;
		mid->next = second_half;
	}
	else {
		prev_of_slow->next = second_half;
	}

	return result;
}

int main() {
	int a[] = {1};
	int n = sizeof(a) / sizeof(int);

	Node *root = create(a, n);
	cout << isPalindrome(root) << endl;

	return 0;
}