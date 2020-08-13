#include<iostream>

using namespace std;

struct Node
{
	struct Node *lchild;
	int data;
	int height;
	struct Node *rchild;
};

int NodeHeight(Node *p) {
	int hl = p && p->lchild ? p->lchild->height : 0;
	int hr = p && p->rchild ? p->rchild->height : 0;

	return max(hl, hr) + 1;
}

int BalanceFactor(Node *p) {
	int hl = p && p->lchild ? p->lchild->height : 0;
	int hr = p && p->rchild ? p->rchild->height : 0;

	return hl - hr;
}

Node * LLRotation(Node *p) {
	Node *pl = p->lchild;
	Node *plr = p->lchild->rchild;

	pl->rchild = p;
	p->lchild = plr;

	p->height = NodeHeight(p);
	pl->height = NodeHeight(pl);

	return pl; //new root is pl
}

Node * LRRotation(Node *p) {
	Node *pl = p->lchild;
	Node *plr = pl->rchild;

	pl->rchild = plr->lchild;
	p->lchild = plr->rchild;

	plr->lchild = pl;
	plr->rchild = p;

	p->height = NodeHeight(p);
	pl->height = NodeHeight(pl);
	plr->height = NodeHeight(plr);

	return plr; //new root is plr
}

Node * RRRotation(Node *p) {
	Node *pr = p->rchild;
	Node *prl = pr->lchild;

	pr->lchild = p;
	p->rchild = prl;

	p->height = NodeHeight(p);
	pr->height = NodeHeight(pr);

	return pr; //new root is pr
}

Node * RLRotation(Node *p) {
	Node *pr = p->rchild;
	Node *prl = pr->lchild;

	p->rchild = prl->lchild;
	pr->lchild = prl->rchild;

	prl->lchild = p;
	prl->rchild = pr;

	return prl; //new root is prl
}

Node * Rinsert(Node *root, int key) {
	if (root == NULL) {
		Node *new_node = new Node;
		new_node->data = key;
		new_node->height = 1;
		new_node->lchild = new_node->rchild = NULL;
		return new_node;
	}

	if (key == root->data) {
		return root;
	}
	else if (key < root->data) {
		root->lchild = Rinsert(root->lchild, key);
	}
	else {
		root->rchild = Rinsert(root->rchild, key);
	}

	root->height = NodeHeight(root); //to update height of each node

	if (BalanceFactor(root) == 2 && BalanceFactor(root->lchild) == 1) {
		root = LLRotation(root);
	}
	else if (BalanceFactor(root) == 2 && BalanceFactor(root->lchild) == -1) {
		root = LRRotation(root);
	}
	else if (BalanceFactor(root) == -2 && BalanceFactor(root->rchild) == -1) {
		root = RRRotation(root);
	}
	else if (BalanceFactor(root) == -2 && BalanceFactor(root->rchild) == 1) {
		root = RLRotation(root);
	}

	return root;
}

Node *InPre(Node *p) {
	while (p->rchild) {
		p = p->rchild;
	}
	return p;
}

Node *InSuc(Node *p) {
	while (p->lchild) {
		p = p->lchild;
	}
	return p;
}

Node *Rdelete(Node *root, Node *p, int key) {
	if (p == NULL) {
		return NULL;
	}
	if (!root->lchild && !root->rchild) {
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
		if (NodeHeight(p->lchild) > NodeHeight(p->rchild)) {
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

	//update height for every node
	p->height = NodeHeight(p);

	if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {  // L1 Rotation
		return LLRotation(p);
	}
	else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1) { // L-1 Rotation
		return LRRotation(p);
	}
	else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 0) { // L0 Rotation
		return LLRotation(p);
	}
	else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1) { // R-1 Rotation
		return RRRotation(p);
	}
	else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1) { // R1 Rotation
		return RLRotation(p);
	}
	else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 0) { // R0 Rotation
		return RRRotation(p);
	}

	return p;
}

void inorder(Node *p) {
	if (p) {
		inorder(p->lchild);
		cout << p->data << " ";
		inorder(p->rchild);
	}
}

int main() {
	Node *root = NULL;
	root = Rinsert(root, 20);
	root = Rinsert(root, 30);
	root = Rinsert(root, 25);

	cout << root->data << endl;
	cout << root->lchild->data << endl;
	cout << root->rchild->data << endl;
}