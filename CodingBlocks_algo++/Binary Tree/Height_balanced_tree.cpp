#include<iostream>
using namespace std;

class HBPair {
public:
	int height;
	bool balanced;
};

HBPair isBalanced(node*root) {
	HBPair p;
	//base
	if (root == NULL) {
		p.height = 0;
		p.balanced = true;
		return;
	}
	// recursive case
	HBPair left = isBalanced(root->left);
	HBPair right = isBalanced(root->right);

	p.height = max(left.height, right.height) + 1;
	if (abs(left.height - right.height) <= 1 and left.balanced and right.balanced)  p.balanced = true;
	else   p.balanced = false;
	return p;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	node*root = buildTree();
	if (isBalanced(root).balanced)  cout << "The Tree is balanced" << endl;
	else  cout << " Tree is not balanced" << endl;
	return 0;
}