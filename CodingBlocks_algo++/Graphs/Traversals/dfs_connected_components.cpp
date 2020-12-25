#include<iostream>
#include<map>
#include<list>
using namespace std;

template<typename T>
class Graph{
	map<T,list<T>> l;
	void dfs_helper(T node,map<T,bool> &visited){
		visited[node] = true;
		cout<<node<<" ";
		for(auto nbr:l[node]){
			if(!visited[nbr]){
				dfs_helper(nbr,visited);
			}
		}
	}
public:
	void addEdge(T x,T y){
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void dfs(){
		map<T,bool> visited;
		for(auto element: l){
			T node = element.first;
			visited[node] = false;
		}
		// call the helper function
		// Iterate over all the nodes & init a dfs call
		int cnt = 0;
		for(auto p:l){
			T node = p.first;
			if(!visited[node]){
				cout<<"In Component "<<cnt++<<" :";
				dfs_helper(node,visited);
				cout<<endl;
			}
		}
	}
};

int main(){
	#ifndef ONLINE_JUDGE
	  freopen("Input.txt", "r", stdin);
	  freopen("Output.txt", "w", stdout);
    #endif
    Graph<int> g;
    g.addEdge(4,0);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.dfs();
	return 0;
}