#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{
	int V;
	list<int> *l;
public:
	Graph(int V){
		this->V = V;
		l = new list<int>[V];
	}

	void addEdge(int x,int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}

	bool is_tree(){
		bool *visited = new bool[V];
		int *parent = new int [V];
		queue<int> q;
		for(int i=0;i<V;i++){
			visited[i] = false;
			parent[i] = i;
		}

		int src = 0;
		q.push(src);
		visited[src] = true;

		while(!q.empty()){
			int node = q.front();
			q.pop();
			for(auto nbr:l[node]){
				if(visited[nbr] and parent[node]!= nbr){
					return false;
				} else if(!visited[nbr]){
					visited[nbr] = true;
					parent[nbr] = node;
					q.push(nbr);
				}
			}
		}
		return true;
	}
};

int main(){
	#ifndef ONLINE_JUDGE
	  freopen("Input.txt", "r", stdin);
	  freopen("Output.txt", "w", stdout);
    #endif
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    // g.addEdge(3,0);
    cout<<g.is_tree()<<endl;
	return 0;
}