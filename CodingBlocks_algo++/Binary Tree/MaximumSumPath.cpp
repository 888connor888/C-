#include<iostream>
#include<climits>
using namespace std;

class node{
public:
	int data;
	node*left;
	node*right;
	node(int d):data(d),left(NULL),right(NULL){}
};

class MaximumSumPath{
private:
	int res = INT_MIN;
	int maxsumUntill(node*current){
		if(current==NULL) return 0;
		int l = maxsumUntill(current->left);
		int r = maxsumUntill(current->right);
		int max_single = max(max(l,r)+current->data,current->data);
		int max_top = max(max_single,l+r+current->data);
		this->res = max(max_top,res);
		return max_single;
	}
public:
	int findMaxSum(node*root){
		maxsumUntill(root);
		return this->res;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
    node*root = new node(10); 
    root->left = new node(2); 
    root->right = new node(10); 
    root->left->left = new node(20); 
    root->left->right = new node(1); 
    root->right->right = new node(-25); 
    root->right->right->left = new node(3); 
    root->right->right->right = new node(4);
    MaximumSumPath s;
    cout<<s.findMaxSum(root)<<endl;
	return 0;
}