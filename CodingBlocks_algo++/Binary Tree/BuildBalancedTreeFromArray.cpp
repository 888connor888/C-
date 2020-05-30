#include<iostream>
#include<queue>
using namespace std;

class node {
public:
	int data;
	node*left;
	node*right;
	node(int d): left(NULL), right(NULL) {
		this->data = d;
	}
};

node* builtTree() {
	int d;
	cin >> d;
	if (d == -1) {
		return NULL;
	}
	node*root = new node(d);
	root->left = builtTree();
	root->right = builtTree();
	return root;
}

void BFS(node*root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {
		node*f = q.front();
		if (f == NULL) {
			cout << endl;
			q.pop();
			if (!q.empty()) q.push(NULL);
		}
		else {
			cout << f->data << " ";
			q.pop();
			if (f->left) q.push(f->left);
			if (f->right) q.push(f->right);
		}
	}
	return;
}

node* BuildBalancedTreeFromArray(int* a, int s, int e) {
	// Base Case
	if (s > e)  return NULL;
	int mid = (s + e) / 2;
	node*root = new node(a[mid]);
	root->left = BuildBalancedTreeFromArray(a, s, mid - 1);
	root->right = BuildBalancedTreeFromArray(a, mid + 1, e);
	return root;
}



int main() {
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	int e = sizeof(a) / sizeof(int);
	node*root = BuildBalancedTreeFromArray(a, 0, e - 1);
	BFS(root);
	return 0;
}