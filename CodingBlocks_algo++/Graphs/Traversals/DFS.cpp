#include<iostream>
#include<map>
#include<list>
using namespace std;

template<typename T>
class Graph{
	map<T,list<T>> l;
	void dfs_helper(T node, map<T,bool> &visited){
		cout<<node<<" ";
		visited[node] = true;

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

	void dfs(T src){
		map<T,bool> visited;
		for(auto element:l){
			T node = element.first;
			visited[node] = false;
		}
		dfs_helper(src,visited);
	}
};


int main(){
	#ifndef ONLINE_JUDGE
	  freopen("Input.txt", "r", stdin);
	  freopen("Output.txt", "w", stdout);
    #endif
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.dfs(2);
	return 0;
}