#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class Stack{
	private:
		vector<T> v;
	public:
		void push(T data){
			v.push_back(data);
		}
		bool empty(){
			return v.size() == 0;
		}
		T top(){
			return v[v.size()-1];
		}
		void pop(){
			if(!empty())  v.pop_back();
		}
};

int main(){
	#ifndef ONLINE_JUDGE
	    freopen("Input.txt","r",stdin);
        freopen("Output.txt","w",stdout);
    #endif
    Stack<int> s;
    // Data Insertion
    for(int i=1;i<7;i++) s.push(i*i);
    // Accessing Data
    while(!s.empty()){
    	cout<<s.top()<<" "; // this will print from last to first.
    	s.pop();
    }
    return 0;
}