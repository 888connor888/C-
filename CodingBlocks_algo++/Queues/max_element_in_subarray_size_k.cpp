#include<iostream>
#include<vector>
#include<deque>
using namespace std;

void slidingWindowK_max(vector<int> v, int k) {
	deque<int> dq;

	// deal with the first k elements
	for (int i = 0; i < k; i++) {
		// remove all the elements which were smaller than the current
		while (!dq.empty() and v[dq.back()] <= v[i])
			dq.pop_back();
		// Insert the next element index
		dq.push_back(i);
	}

	// handle the rest of the elements one at a time from v[k] to v[v.size() -1]
	for (int i = k; i < v.size(); i++) {
		// print the max element in current window
		cout << v[dq.front()] << " ";

		// remove the elements which out for the next window
		while (!dq.empty() and dq.front() <= i - k)
			dq.pop_front();

		// now add the next element in the window which is index i

		// remove all the elements which were smaller than the current
		while (!dq.empty() and v[dq.back()] <= v[i])
			dq.pop_back();
		dq.push_back(i);
	}
	// print the last max element
	cout << v[dq.front()];
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	int m, k;
	cin >> k;
	vector<int> v;
	int i = 0;
	while (scanf("%d", &m) != EOF) v.push_back(m);
	slidingWindowK_max(v, k);
	return 0;
}