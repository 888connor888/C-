#include<iostream>
#include<climits>
#include<queue>
using namespace std;

class node{
public:
	int data;
	node*left;
	node*right;
	node(int d):data(d),left(NULL),right(NULL){}
};

class BST{
private:
	node* insertBST(node*root,int d){
		if(root == NULL) return new node(d);
		if(d <= root->data) root->left = insertBST(root->left,d);
		else root->right = insertBST(root->right,d);
		return root;
	}
public:
	node* build(){
		int d;
		cin>>d;
		node*root = NULL;
		while(d!=-1){
			root = insertBST(root,d);
			cin>>d;
		}
		return root;
	}
	void BFS(node*root){
		queue<node*> q;
		q.push(root);
		q.push(NULL);
		while(!q.empty()){
			node*f = q.front();
			if( f == NULL){
				cout<<endl;
				q.pop();
				if(!q.empty()) q.push(NULL);
			}
			else{
				cout<<f->data<<" ";
				q.pop();
				if(f->left) q.push(f->left);
				if(f->right) q.push(f->right);
			}
		}
		return;
	}
	bool search(node*root,int key){
		if(root == NULL) return false;
		if(key == root->data) return true;
		if(key <= root->data) return search(root->left,key);
		else return search(root->right,key);
	}
	node* deleteNode(node*root,int key){
		if(root == NULL) return NULL;
		if(key < root->data){
			root->left = deleteNode(root->left,key);
			return root;
		}
		if(key == root->data){
			// case 1
			if(root->left == NULL and root->right == NULL){
				delete root;
				return NULL;
			}
			// case 2
			if(root->left!=NULL and root->right == NULL){
				node*temp = root->left;
				delete root;
				return temp;
			}
			if(root->right!=NULL and root->left == NULL){
				node*temp = root->right;
				delete root;
				return temp;
			}
			//case 3
			if(root->left != NULL and root->right != NULL){
				node*replace = root->right;
				while(replace->left!= NULL) replace = replace->left;
				root->data == replace->data;
				root->right = deleteNode(root->right,replace->data);
				return root;
			}
		}
		else {
			root->right = deleteNode(root->right,key);
			return root;
		}
	}
	bool isBST(node*root,int minv = INT_MIN,int maxv = INT_MAX){
		if(root == NULL) return true;
		if(root->data > minv and root->data < maxv and isBST(root->left,minv,root->data) and isBST(root->right,root->data,maxv)) return true;
		return false;
	}
};

class LinkedList{
public:
	node*head;
	node*tail;
};

LinkedList flatten(node*root){
	LinkedList l;
	if(root == NULL) {
		l.head = l.tail = NULL;
	}
	if(root->left == NULL and root->right == NULL){ // Leaf Node
		l.head = l.tail = root;
		return l;
	}
	if(root->left != NULL and root->right == NULL){  // If there is no right sub tree
		LinkedList leftL = flatten(root->left);
		leftL.tail->right = root;
		l.head = leftL.head;
		l.tail = root;
		return l;
	}
	if(root->left == NULL and root->right != NULL){ // If there is no right sub tree
		LinkedList rightL = flatten(root->right);
		root->right = rightL.head;

		l.head = root;
		l.tail = rightL.tail;
		return l;
	}
	// Working on the root of post order traversal
	// Both sides are not NULL
	LinkedList rightLL = flatten(root->right);
	LinkedList leftLL = flatten(root->left);

    // Join leftll, rightLL and root
    leftLL.tail->right = root;
    root->right = rightLL.head;
    
    // form current LL and return 
	l.head = leftLL.head;
	l.tail = rightLL.tail;
	return l;
}

void printList(LinkedList l){
	cout<<endl<<"Flattened Tree : ";
	while(l.head->right!=NULL){
		cout<< l.head->data<<" ";
		l.head = l.head->right;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	  freopen("Input.txt", "r", stdin);
	  freopen("Output.txt", "w", stdout);
    #endif
    BST b;
    node*root = b.build();
    b.BFS(root);
    // if(b.search(root,8)) cout<< "Yes!"<<endl;
    // b.deleteNode(root,6);
    // b.BFS(root);
    // if(b.isBST(root)) cout<<"Is a BST!";
    LinkedList l = flatten(root);
    node*temp = l.head;
    while(temp != NULL){
    	cout<<temp->data<<" ";
    	temp = temp->right;
    }
	return 0;
}