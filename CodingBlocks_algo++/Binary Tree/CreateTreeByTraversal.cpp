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


node* CreatTreeFromTraversal(int* in, int* pre, int s, int e) {
	static int i = 0;
	// Base Case
	if (s > e)  return NULL;
	//Recursive Case
	node*root = new node(pre[i]);
	int index = -1;
	for (int j = s; j <= e; j++) {
		if (in[j] == pre[i]) {
			index = j;
			break;
		}
	}
	i++;
	root->left = CreatTreeFromTraversal(in, pre, s, index - 1);
	root->right = CreatTreeFromTraversal(in, pre, index + 1, e);
	return root;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
	int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
	int e = sizeof(in) / sizeof(int);
	node*root = CreatTreeFromTraversal(in, pre, 0, e - 1);
	BFS(root);
	return 0;
}