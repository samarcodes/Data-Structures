//insert, delete, inorder traversal, searching

#include<iostream>

using namespace std;

struct Node
{
	struct Node *lchild;
	int data;
	struct Node *rchild;
};

Node * Rinsert(Node *root, int key) {
	//base case
	if (root == NULL) {
		Node *new_node = new Node;
		new_node->data = key;
		new_node->lchild = new_node->rchild = NULL;
		return new_node;
	}

	if (key < root->data) {
		root->lchild = Rinsert(root->lchild, key);
	}
	else if (key > root->data) {
		root->rchild = Rinsert(root->rchild, key);
	}
	return root;
}

Node * Iinsert(Node *root, int key) {
	Node *new_node;
	Node *tail = NULL;
	Node *head = root;
	while (head) {
		if (key == head->data) {
			return root;
		}
		else if (key < head->data) {
			tail = head;
			head = head->lchild;
		}
		else {
			tail = head;
			head = head->rchild;
		}
	}

	new_node = new Node;
	new_node->data = key;
	new_node->lchild = new_node->rchild = NULL;

	if (root && (key < tail->data)) {
		tail->lchild = new_node;
	}
	else if (root && (key > tail->data)) {
		tail->rchild = new_node;
	}
	else {
		root = new_node;
	}

	return root;
}

int height(Node *p) {
	if (p) {
		int x = height(p->lchild);
		int y = height(p->rchild);
		return max(x, y) + 1;
	}
	return 0;
}

Node * InPre(Node *p) {
	while (p && p->rchild) {
		p = p->rchild;
	}
	return p;
}

Node * InSuc(Node *p) {
	while (p && p->lchild) {
		p = p->lchild;
	}
	return p;
}

Node * Rdelete(Node *root, Node *p, int key) {
	if (p == NULL) {
		return NULL;
	}

	if (p->lchild == NULL && p->rchild == NULL) {
		if (p == root) {
			root = NULL;
		}
		delete p;
		return NULL;
	}

	if (key < p->data) {
		p->lchild = Rdelete(root, p->lchild, key);
	}
	else if (key > p->data) {
		p->rchild = Rdelete(root, p->rchild, key);
	}
	else {
		Node *q;
		if (height(p->lchild) > height(p->rchild)) {
			q = InPre(p->lchild);
			p->data = q->data;
			p->lchild = Rdelete(root, p->lchild, q->data);
		}
		else {
			q = InSuc(p->rchild);
			p->data = q->data;
			p->rchild = Rdelete(root, p->rchild, q->data);
		}
	}
}

void Rinorder(Node * p) {
	if (p) {
		Rinorder(p->lchild);
		cout << p->data << " ";
		Rinorder(p->rchild);
	}
}

Node * RSearch(Node * root, int key) {

	//base case
	if (root == NULL) {
		return NULL;
	}

	if (key == root->data) {
		return root;
	}
	else if (key < root->data) {
		RSearch(root->lchild, key);
	}
	else {
		RSearch(root->rchild, key);
	}
}

Node * ISearch(Node * root, int key) {
	Node *p = root;

	//base case
	if (root == NULL) {
		return NULL;
	}

	while (p) {
		if (key == p->data) {
			return p;
		}
		else if (key < p->data) {
			p = p->lchild;
		}
		else {
			p = p->rchild;
		}
	}
	return NULL;
}

int main() {
	Node *root = NULL;

	root = Iinsert(root, 30);
	Iinsert(root, 20);
	Iinsert(root, 10);
	Iinsert(root, 15);
	Iinsert(root, 40);
	Iinsert(root, 35);

	Rinorder(root);
	cout << endl;

	Node *ans = ISearch(root, 30);
	if (ans) {
		cout << ans->data << endl;
	}
	else {
		cout << "Not Found" << endl;
	}

	Node *del = Rdelete(root, root, 30);
	if (del) {
		Rinorder(del);
		cout << endl;
	}
	else {
		cout << "Not Found" << endl;
	}

	return 0;
}