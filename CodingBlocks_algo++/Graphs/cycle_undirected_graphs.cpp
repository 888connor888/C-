// Depth First Search Approach
#include<iostream>
#include<list>
using namespace std;

class Graph{
	int V;
	list<int>* l;
	bool cycle_helper(int node,bool *visited,int parent){
		visited[node] = true;
		// two cases
		for(auto nbr:l[node]){
			if(!visited[nbr]){
				// go recursively visit the nbr
				bool potential_cycle = cycle_helper(nbr,visited,node);
				if(potential_cycle) return true;
			}
			// nbr is visited but not equal to parent 
			else if(nbr != parent){
				return true;
			}
		}
		return false;
	}
public:
	Graph(int V){
		this->V = V;
		l = new list<int>[V];
	}
	void addEdge(int x,int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}
	bool contains_cycle(){
		bool *visited = new bool[V];
		for(int i=0;i<V;i++){
			visited[i] = false;
		}
		return cycle_helper(0,visited,-1);
	}
};

int main(){
	#ifndef ONLINE_JUDGE
	  freopen("Input.txt", "r", stdin);
	  freopen("Output.txt", "w", stdout);
    #endif
    Graph g(5);
    g.addEdge(1,0);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(3,2);
    g.addEdge(2,1);
    cout<<g.contains_cycle()<<endl;
	return 0;
}