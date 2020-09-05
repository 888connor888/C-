#include<iostream>
#include<climits>
#include<map>
#include<list>
#include<queue>
using namespace std;

template<typename T>
class Graph{
	map<T,list<T>> l;
public:
	void addEdge(int x,int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void BFS_path(T src){
		queue<T> q;
		map<T,int> dist;

		for(auto node_pair:l){
			T node = node_pair.first;
			dist[node] = INT_MAX;
		}

		q.push(src);
		dist[src] = 0;

		while(!q.empty()){
			T node = q.front();
			q.pop();
			for(auto nbr:l[node]){
				if(dist[nbr]==INT_MAX){
					q.push(nbr);
					dist[nbr] = dist[node] + 1;
				}
			}
		}
		for(auto node_pair:l){
			T node = node_pair.first;
			cout<<"Node: "<<node<<"dist from source :"<<dist[node]<<endl;
		}

	}
};


int main() {
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
    Graph<int> g;
    g.addEdge(1,2);
    g.addEdge(1,0);
    g.addEdge(2,3);
    g.addEdge(3,0);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.BFS_path(0);
	return 0;
}