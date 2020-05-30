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

int diameter(node*root) {
	if (root == NULL) return 0;
	int h1 = Height_ofTree(root->left);
	int h2 = Height_ofTree(root->right);
	int opt1 = h1 + h2;
	int opt2 = diameter(root->left);
	int opt3 = diameter(root->right);
	return max(opt1, max(opt2, opt3));
}

// first is height and second in diameter
pair<int, int> fastDiameter(node*root) {
	pair<int, int> p;
	if (root == NULL) {
		p.first = p.second = 0;
		return p;
	}
	pair<int, int> left = fastDiameter(root->left);
	pair<int, int> right = fastDiameter(root->right);
	// Calculate height & diameter in post order traversal
	p.first = max(left.first, right.first) + 1;
	p.second = max(left.first + right.first, max(left.second, right.second));
	return p;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	node*root = builtTree();
	// Preorder_print(root);
	// cout << endl;
	// Inorder_print(root);
	// cout << endl;
	// Postorder_print(root);
	// cout << endl << Height_ofTree(root) << endl;
	// KthLevel_print(root, 3);
	// cout << endl;
	// BFS(root);
	cout << count(root) << endl;
	cout << sum(root) << endl;
	cout << diameter(root) << endl;
	cout << fastDiameter(root).second << endl;
	return 0;
}