#include<iostream>
#include<climits>
#include<queue>
using namespace std;

// Inorder Print of BST is allways sorted

class node {
public:
	int data;
	node*left;
	node*right;
	node(int d): data(d), left(NULL), right(NULL) {}
};

class BST {
private:
	node* insertInBST(node*root, int d) {
		if (root == NULL) return new node(d);
		if (d <= root->data) root->left = insertInBST(root->left, d);
		else root->right = insertInBST(root->right, d);
		return root;
	}
public:
	node* build() {
		int d;
		cin >> d;
		node*root = NULL;
		while (d != -1) {
			root = insertInBST(root, d);
			cin >> d;
		}
		return root;
	}
	// Print
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
	//  Searching Operation
	bool search(node*root, int data) {
		if (root == NULL) return false;
		if (root->data == data) return true;
		if (data <= root->data) return search(root->left, data);
		else return search(root->right, data);
	}
	// Deletion operation
	node* deleteNode(node*root, int target) {
		if (root == NULL) return NULL;
		if (target < root->data) root->left = deleteNode(root->left, target);
		else if (root->data == target) {
			if (root->left == NULL and root->right == NULL) {
				delete root;
				return NULL;
			}
			else if (root->left != NULL and root->right == NULL) {
				node*temp = root->left;
				delete root;
				return temp;
			}
			else if (root->left == NULL and root->right != NULL) {
				node*temp = root->right;
				delete root;
				return temp;
			}
			else {
				node*replace = root->right;
				while (replace->left != NULL) replace = replace->left;
				root->data = replace->data;
				root->right = deleteNode(root->right, replace->data);
				return root;
			}
		}
		else root->right = deleteNode(root->right, target);
		return root;
	}
	bool isBST(node*root, int minv = INT_MIN, int maxv = INT_MAX) {
		if (root == NULL) return true;
		if (root->data > minv and root->data < maxv and isBST(root->left, minv, root->data) and isBST(root->right, root->data, maxv)) return true;
		return false;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	BST b;
	node*root = b.build();
	b.BFS(root);
	if (b.search(root, 10)) cout << "Present" << endl;
	else cout << "Not Present" << endl;
	// b.deleteNode(root, 5);
	// b.BFS(root);
	if (b.isBST(root)) cout << "Yes";
	else cout << "No";
	return 0;
}