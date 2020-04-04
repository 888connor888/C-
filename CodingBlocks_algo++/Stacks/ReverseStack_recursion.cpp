#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s,int x){
	// Base Case
	if(s.empty()){
		s.push(x);
		return;
	}
	// Recusive Case
	int y = s.top();
	s.pop();
	insertAtBottom(s,x);
	s.push(y);
}

void reverseStack_recursive(stack<int> &s){
	// Base Case
	if(s.empty())  return;
	// Recursive Case
	int x = s.top();
	s.pop();
	reverseStack_recursive(s);
	insertAtBottom(s,x);
}

int main(){
	#ifndef ONLINE_JUDGE
	    freopen("Input.txt","r",stdin);
        freopen("Output.txt","w",stdout);
    #endif
    stack<int> s;
    for(int i=1;i<=5;i++)    s.push(i*i);
    reverseStack_recursive(s);
    while(!s.empty()){
    	cout<<s.top()<<" ";
    	s.pop();
    }
    return 0;
}