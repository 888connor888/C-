#include<iostream>
#include<list>
using namespace std;

class Graph{
	int V;
	list<int> *l;
	bool cycle_helper(int node,bool *visited,bool *stack){
		// visit a node
		visited[node] = true;
		stack[node] = true;

		for(auto nbr:l[node]){
			if(stack[nbr]) return true; // nbr part of the current path
			else if(!visited[nbr]){ // nbr can Potentially be part of cycle
				bool potential_cycle = cycle_helper(nbr,visited,stack);
				if(potential_cycle) return true;
			}
		}
		// leave a node
		stack[node] = false;
		return false;
	}
public:
	Graph(int V){
		this->V = V;
		l = new list<int>[V];
	}
	void addEdge(int x,int y){
		// Directed
		l[x].push_back(y);
	}
	bool contains_cycle(){
		bool *visited = new bool[V];
		bool *stack = new bool[V];
		for(int i=0;i<V;i++){
			visited[i] = false;
			stack[i] = false;
		}
		return cycle_helper(0,visited,stack);
	}
};

int main(){
	#ifndef ONLINE_JUDGE
	  freopen("Input.txt", "r", stdin);
	  freopen("Output.txt", "w", stdout);
    #endif
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(1,5);
    g.addEdge(4,2);
    cout<<g.contains_cycle();
	return 0;
}