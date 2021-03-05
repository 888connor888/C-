#include<iostream>
#include<cstring>
#include<list>
#include<map>
using namespace std;

class graph{
private:
	map<string,list<string>> l;
public:
	void addEdge(string x,string y){
		l[x].push_back(y);
	}

	void dfs_helper(string src,map<string,bool> &visited,list<string> &ordering){
		visited[src] = true;

		for(auto nbr:l[src]){
			if(!visited[nbr]){
				dfs_helper(nbr,visited,ordering);
			}
		}
		ordering.push_front(src);
		return;
	}

	void dfs(){
		map<string,bool> visited;
		list<string> ordering;

		// Init the bool list
		for(auto p:l){
			string node = p.first;
			visited[node] = false;
		}

		// call the helper function
		for(auto p:l){
			string node = p.first;
			if(!visited[node]){
				dfs_helper(node,visited,ordering);
			}
		}

		// finally print the list
		for(string node:ordering){
			cout<<node<<endl;
		}
	}
};

int main(){
	graph g;
	g.addEdge("Python","Data Preprocessing");
	g.addEdge("Python","ML Basic");
	g.addEdge("Python","Pytorch");
	g.addEdge("Pytorch","DeepLearning");
	g.addEdge("Data Preprocessing","ML Basic");
	g.addEdge("ML Basic","DeepLearning");
	g.addEdge("DeepLearning","FaceRecognition");
	g.addEdge("Dataset","FaceRecognition");
	g.dfs();
}
