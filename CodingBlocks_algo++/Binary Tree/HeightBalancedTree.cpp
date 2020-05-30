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

class HBPair {
public:
	int height;
	bool balanced;
};

HBPair HeightBalancedTree(node*root) {
	HBPair tree;
	//Base
	if (root == NULL) {
		tree.height = 0;
		tree.balanced = false;
		return tree;
	}
	// Recursive Case
	HBPair left = HeightBalancedTree(root->left);
	HBPair right = HeightBalancedTree(root->right);
	// Post order traversal
	tree.height = max(left.height, right.height) + 1;
	if (abs(left.height - right.height) <= 1 and left.balanced and right.balanced) tree.balanced = true;
	else tree.balanced = false;
	return tree;
}

int main() {
	node*root = builtTree();
	//cout << replaceSum(root) << endl;
	//BFS(root);
	if (HeightBalancedTree(root).balanced)  cout << "Balanced" << endl;
	else cout << "Not Balanced!" << endl;
	return 0;
}