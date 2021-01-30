#include<iostream>
#include<map>
#include<list>
using namespace std;

class Graph{
	map<int,list<int>> l;
	bool cycle_helper(int node,map<int,bool> &visited,int parent){
		visited[node] = true;
		for(auto nbr:l[node]){
			if(!visited[nbr]){
				// recursively visit the node
				bool potential_cycle = cycle_helper(nbr,visited,node); // look for potential cycle
				if(potential_cycle){
					return true; // return true is cycle present 
				}
			}
			else if(nbr!=parent){
				// if the current nbr is'nt the parent of node
				return true;
			}
		}
		return false;
	}
public:
	void addEdge(int x,int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}
	bool contains_cycle(){
		map<int,bool> visited;
		for(auto p:l){
			int node = p.first;
			visited[node] = false;
		}
		bool cyclePresent = cycle_helper(0,visited,-1);
		return cyclePresent;
	}
};

int main(){
	#ifndef ONLINE_JUDGE
	  freopen("Input.txt", "r", stdin);
	  freopen("Output.txt", "w", stdout);
    #endif
    Graph g;
    g.addEdge(1,0);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(3,2);
    g.addEdge(2,1);
    if(g.contains_cycle()) cout<<"Cycle Present"<<endl;
    else cout<<"No cycle present"<<endl;
	return 0;
}