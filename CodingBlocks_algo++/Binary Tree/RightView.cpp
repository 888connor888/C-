#include<iostream>
#include<queue>
#include<vector>
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

class Solution {
public:
	int max_level = -1;
	vector<int> v;
	void helper(node*root, int level) {
		// Base case
		if (root == NULL)  return;
		if (level > max_level) {
			max_level = level;
			v.push_back(root->data);
		}
		helper(root->right, level + 1);
		helper(root->left, level + 1);
	}
	vector<int> rightView(node*root) {
		helper(root, 0);
		return v;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	node*root = builtTree();
	Solution s;
	vector<int> v = s.rightView(root);
	for (auto it = v.begin(); it != v.end(); it++)  cout << (*it) << endl;
	//BFS(root);
	return 0;
}