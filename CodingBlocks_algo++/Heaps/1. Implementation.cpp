#include<iostream>
#include<vector>
using namespace std;

void upheapify(vector<int> &heap, int idx) {
	if (idx == 0) return;
	int parentIdx = (idx - 1) / 2;
	if (heap[parentIdx] < heap[idx]) {
		swap(heap[parentIdx], heap[idx]);
		upheapify(heap, parentIdx);
	}
	else return;
}

void insert(vector<int> &heap, int x) {
	heap.push_back(x);
	upheapify(heap, heap.size() - 1);
}


void display(vector<int> v) {
	for (auto it = v.begin(); it != v.end(); it++) cout << (*it) << " " ;
	cout << endl;
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	vector<int> v;
	int x;
	while (scanf("%d", &x) != EOF) {
		insert(v, x);
	}
	display(v);
	return 0;
}