#include<iostream>
#include<vector>
using namespace std;

bool min_heap = false;

bool compare(int a,int b){
	if(min_heap) return a<b;
	else return a>b;
}

void heapify(int idx,vector<int> &v){
	int max_idx = idx;
	int last_idx = v.size() - 1;
	int left = 2*idx;
	int right = left + 1;
	if(left <= last_idx and compare(v[left],v[idx])) max_idx = left;
	if(right <= last_idx and compare(v[right],v[max_idx])) max_idx = right;
	if(max_idx!=idx){
		swap(v[max_idx],v[idx]);
		heapify(max_idx,v);
	}
}

void buildHeap(vector<int> &v){
	for(int i= (v.size()-1/2);i>=1;i--){
		heapify(i,v);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	  freopen("Input.txt", "r", stdin);
	  freopen("Output.txt", "w", stdout);
    #endif
    vector<int> v;
    v.push_back(-1);
    int no;
    while(scanf("%d",&no)!=EOF) v.push_back(no);
    buildHeap(v);
    for(int i = 0;i<v.size();i++) cout<<v[i]<<" ";
	return 0;
}