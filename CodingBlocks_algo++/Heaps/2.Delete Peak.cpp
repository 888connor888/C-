#include<iostream>
#include<vector>
using namespace std;

class heap {
public:
	//
};

void upheapify(vector<int> &heap, int idx) {
	if (idx == 0) return;
	int parentIdx = (idx - 1) / 2;
	if (heap[parentIdx] < heap[idx]) {
		swap(heap[parentIdx], heap[idx]);
		upheapify(heap, parentIdx);
	}
	else return;
}

void insert(vector<int> &heap, int data) {
	heap.push_back(data);
	upheapify(heap, heap.size() - 1);
}

void downheapify(vector<int> heap, int idx) {
	int leftIdx = 2 * idx + 1;
	int rightIdx = 2 * idx + 2;
	if (leftIdx >= heap.size() and rightIdx >= heap.size()) return; // if it is a leaf node
	int largestIdx = idx;
	// find the index with larger element
	if (leftIdx < heap.size() and heap[largestIdx] < heap[leftIdx]) largestIdx = leftIdx;
	if (rightIdx < heap.size() and heap[largestIdx] < heap[rightIdx]) largestIdx = rightIdx;
	if (largestIdx == idx) return;
	swap(heap[largestIdx], heap[idx]);
	downheapify(heap, largestIdx);
}

void deletePeak(vector<int> heap) {
	swap(heap[0], heap[heap.size() - 1]);
	heap.pop_back();
	downheapify(heap, 0);
}




int main() {
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	vector<int> v;
	int x;
	while (scanf("%d", &x) != EOF) insert(v, x);
	for (auto it = v.begin(); it != v.end(); it++) cout << (*it) << " ";
	deletePeak(v);
	for (auto it = v.begin(); it != v.end(); it++) cout << (*it) << " ";
	return 0;
}