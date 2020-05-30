#include<iostream>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;

	node(int d): left(NULL), right(NULL) {
		this->data = d;
	}
};

node* buildTree() {
	int d;
	cin >> d;

	if (d == -1) return NULL;

	node* root = new node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

void PrintPreorder(node*root) {
	if (root == NULL)   return;
	cout << root->data << " ";
	PrintPreorder(root->left);
	PrintPreorder(root->right);
}

void PrintInorder(node*root) {
	if (root == NULL)  return;
	PrintInorder(root->left);
	cout << root->data << " ";
	PrintInorder(root->right);
}

void PrintPostorder(node*root) {
	if (root == NULL) return;
	PrintPostorder(root->left);
	PrintPostorder(root->right);
	cout << root->data << " ";
}

void PrintKthLevel(node*root, int k) {
	if (root == NULL)  return;
	if (k == 1) {
		cout << root->data << " ";
		return;
	}
	PrintKthLevel(root->left, k - 1);
	PrintKthLevel(root->right, k - 1);
	return;
}

int height_BT(node*root) {
	if (root == NULL) return 0;
	int ls = height_BT(root->left);
	int rs = height_BT(root->right);
	return (max(ls, rs) + 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	node*root = buildTree();
	PrintPreorder(root);
	cout << endl;
	PrintInorder(root);
	cout << endl;
	PrintPostorder(root);
	cout << endl;
	PrintKthLevel(root, 3);
	cout << " " << height_BT(root) << endl;
	return 0;
}