//tree creation and traversals
//count nodes
//cal height

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct Node
{ 	
	struct Node *lchild;
	int data;
	struct Node *rchild;
};

Node * create_tree() {
	//for storing node addresses
	queue <Node *> q; 

	struct Node *root,*p,*t;

	int x;
	cout<<"enter root value : ";
	cin>>x;

	//root node
	root=new Node;
	root->data=x;
	root->lchild = root->rchild = NULL;
	q.push(root);

	while(!q.empty()) {
		p=q.front();
		q.pop();
		cout<<"enter left child of "<<p->data<<" : ";
		cin>>x;

		if(x!=-1) {
			t=new Node;
			t->data=x;
			t->lchild = t->rchild = NULL;
			p->lchild=t;
			q.push(t); 
		}

		cout<<"enter right child of "<<p->data<<" : ";
		cin>>x;

		if(x!=-1) {
			t=new Node;
			t->data=x;
			t->lchild = t->rchild = NULL;
			p->rchild=t;
			q.push(t); 
		}
	}
	return root;
}


//recursive preorder (Root Left Right)
void Rpreorder(struct Node *p) {
	if(p) {
		cout<<p->data<<" ";
		Rpreorder(p->lchild);
		Rpreorder(p->rchild);
	}
}

//iterative preorder
void Ipreorder(Node *p) {
	//stack is used to store last encountered node address
	stack <Node *> st;

	while(p!=NULL || !st.empty()) {
		
		if(p!=NULL) {
			cout<<p->data<<" ";
			st.push(p);
			p=p->lchild;
		}
		else {
			p=st.top();
			st.pop();
			p=p->rchild;
		}
	}
}

//recusive inorder (Left Root Right)
void Rinorder(struct Node *p) {
	if(p) {
		Rinorder(p->lchild);
		cout<<p->data<<" ";
		Rinorder(p->rchild);
	}
}

//iterative inorder
void Iinorder(Node *p) {
	stack <Node *> st;

	while(p!=NULL || !st.empty()) {
		if(p!=NULL) {
			st.push(p);
			p=p->lchild;
		}
		else {
			p=st.top();
			st.pop();
			cout<<p->data<<" ";
			p=p->rchild;
		}
	}
}

//Recursive postorder(Left Right Root)
void Rpostorder(struct Node *p) {
	if(p) {
		Rpostorder(p->lchild);
		Rpostorder(p->rchild);
		cout<<p->data<<" ";
	}
}

//iterative postorder
void Ipostorder(Node *p) {
	stack <Node *> st;

	while(p!=NULL || !st.empty()) {

	}
}

void Ilevelorder(Node *p) {
	queue <Node *> q;

	cout<<p->data<<" ";
	q.push(p);

	while(!q.empty()) {
		p=q.front();
		q.pop();

		if(p->lchild) {
			cout<<p->lchild->data<<" ";
			q.push(p->lchild);
		}
		if(p->rchild) {
			cout<<p->rchild->data<<" ";
			q.push(p->rchild);
		}
	}
}

int count_node(Node *p) {

	int x,y;

	if(p) {
		x=count_node(p->lchild);
		y=count_node(p->rchild);
		return x+y+1;
	}
	return 0;
}

int count_leaf(Node *p) {
	if(p) {
		int x=count_leaf(p->lchild);
		int y=count_leaf(p->rchild);

		if(!p->lchild && !p->rchild) {
			return x+y+1;
		}
		else {
			return x+y;
		}
	}
	return 0;
}

int count_2(Node *p) {
	if(p) {
		int x=count_2(p->lchild);
		int y=count_2(p->rchild);

		if(p->lchild && p->rchild) {
			return x+y+1;
		}
		else {
			return x+y;
		}
	}
	return 0;
}

int count_internal(Node *p) {
	if(p) {
		int x=count_internal(p->lchild);
		int y=count_internal(p->rchild);

		if(p->lchild || p->rchild) {
			return x+y+1;
		}
		else {
			return x+y;
		}
	}
	return 0;
}

int count_1(Node *p) {
	if(p) {
		int x=count_1(p->lchild);
		int y=count_1(p->rchild);

		if((p->lchild && !p->rchild) || (!p->lchild && p->rchild)) {
			return x+y+1;
		}
		else {
			return x+y;
		}
	}
	return 0;
}

int height(Node *p) {
	int x,y;

	if(p) {
		x=height(p->lchild);
		y=height(p->rchild);
		return max(x,y)+1;
	}
	return 0;
}

int main() 
{
	Node * root;
	root=create_tree();

	Ilevelorder(root);
	cout<<endl;
	cout<<"No of nodes = "<<count_node(root)<<endl;
	cout<<"Height = "<<height(root)-1<<endl;
	return 0;
}