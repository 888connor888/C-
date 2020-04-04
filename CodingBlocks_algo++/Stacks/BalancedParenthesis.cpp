#include<iostream>
#include<stack>
using namespace std;

bool BalancedParenthesis(string str){
	stack<char> s;
	for(int i=0;i<str.size();i++){
		char currentChar = str[i];
		if(currentChar == '('){
		   s.push(currentChar);
		}
		else if(currentChar == ')'){
			if(s.empty()) return false;
			s.pop();
		}
	}
	return s.empty();
}

int main(){
	#ifndef ONLINE_JUDGE
	    freopen("Input.txt","r",stdin);
        freopen("Output.txt","w",stdout);
    #endif
    string str;
    cin>>str;
    if(BalancedParenthesis(str))  cout<<"Balanced"<<endl;
    return 0;
}