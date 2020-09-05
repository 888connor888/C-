#include<iostream>
#include<list>
using namespace std;

class Graph{
	int v;
	list<int> *l;
public:
	Graph(int v){
		this->v = v;
		l = new list<int> [v];
	}
	void addEdge(int x,int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void printAdList(){
		for(int i = 0;i<v;i++){
			printf("Vertex %d: ",i);
			for(auto it:l[i]) cout<<it<<",";
			printf("\n");
		}
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,2);
	g.addEdge(2,3);
	g.printAdList();
	return 0;
}