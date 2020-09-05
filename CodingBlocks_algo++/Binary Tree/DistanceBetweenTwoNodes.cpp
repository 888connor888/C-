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
	node* lowestCommonAncestor(node*root, node* p, node* q) {
		// node*P = findNode(root, p).second;
		// node*Q = findNode(root, q).second;
		recurse(root, p, q);
		return ans;
	}
};

class DistanceofTwoNodes{
	pair<int,bool> rootDistance(node*current,node*target){
		pair<int,bool> p;
		if(current==NULL){
			p.first = 0;
			p.second = false;
			return p;
		}
		if(current == target){
			p.first = 1;
			p.second = true;
			return p;
		}
        pair<int,bool> lp = rootDistance(current->left,target);
        pair<int,bool> rp = rootDistance(current->right,target);
        if(lp.second == true) p = lp;
        else if(rp.second == true) p = rp;
        p.first++;
		return p;
	}
public:
	int Distance(node*root, node*p, node*q) {
		LowestCommonAncestor l;
		node*lca = l.lowestCommonAncestor(root, p, q);
		pair<int,bool> dist_p = rootDistance(root, p);
		pair<int,bool> dist_q = rootDistance(root, q);
		pair<int,bool> dist_lca = rootDistance(root, lca);
		return (dist_p.first + dist_q.first - (2 * dist_lca.first));
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
	cout << d.Distance(root, root->left->left->left,root->right->left) << endl;
	return 0;
}