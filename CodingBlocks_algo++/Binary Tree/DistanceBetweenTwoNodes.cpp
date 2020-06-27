#include<iostream>
#include<queue>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
	node(int d): data(d), left(NULL), right(NULL) {}
};

node* BuiltList() {
	int d;
	cin >> d;
	if (d == -1) return NULL;
	node*root = new node(d);
	root->left = BuiltList();
	root->right = BuiltList();
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

class LowestCommonAncestor {
private:
	node*ans = NULL;
	bool recurse(node*current, node*p, node*q) {
		if (current == NULL) return false;
		int left = recurse(current->left, p, q) ? 1 : 0;
		int right = recurse(current->right, p, q) ? 1 : 0;
		int mid = (current == p or current == q) ? 1 : 0;
		if ((left + right + mid) >= 2) this->ans = current;
		return ((left + right + mid) > 0);
	}
	pair<bool, node*> findNode(node*root, const int target) {
		pair<bool, node*> p;
		if (root == NULL) {
			p.first = false;
			p.second = NULL;
			return p;
		}
		if (root->data == target) {
			p.first = true;
			p.second = root;
			return p;
		}
		pair<bool, node*> left = findNode(root->left, target);
		pair<bool, node*> right = findNode(root->right, target);
		if (left.first == true) p = left;
		else p = right;
		return p;
	}
public:
	node* lowestCommonAncestor(node*root, const int p, const int q) {
		node*P = findNode(root, p).second;
		node*Q = findNode(root, q).second;
		recurse(root, P, Q);
		return ans;
	}
};

class DistanceofTwoNodes {
private:
	int findDistance(node*current, int target) {
		if (current == NULL) return -1;
		int dist = -1;
		if ((current->data == target) or (dist = findDistance(current->left, target)) >= 0 or (dist = findDistance(current->right, target)) >= 0) return dist + 1;
		return dist;
	}
public:
	int Distance(node*root, int p, int q) {
		LowestCommonAncestor l;
		node*lca = l.lowestCommonAncestor(root, p, q);
		int dist_p = findDistance(root, p);
		int dist_q = findDistance(root, q);
		int dist_lca = findDistance(root, lca->data);
		return (dist_p + dist_q - (2 * dist_lca));
	}

};

int main() {
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	node*root = BuiltList();
	cout << "Tree:" << endl;
	BFS(root);
	DistanceofTwoNodes d;
	cout << d.Distance(root, 8, 10) << endl;
	return 0;
}