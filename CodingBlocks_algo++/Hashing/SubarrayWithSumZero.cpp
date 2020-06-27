#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

bool checkSubarrayWithSumZero(vector<int> v) {
	unordered_set<int> s;
	int pre;
	for (auto it = v.begin(); it != v.end(); it++) {
		pre += (*it);
		if (pre == 0 or s.find(pre) != s.end()) return true;
		s.insert(pre);
	}
	return false;
}

int LongestSubarrayWithSumZero(vector<int> v) {
	unordered_map<int, int> mp;
	int pre = 0;
	int len = 0;
	for (int i = 0; i < v.size() ; i++) {
		pre += v[i];
		if (v[i] == 0 and len == 0) len = 1;
		if (pre == 0) len = max(len, i + 1);
		if (mp.find(pre) != mp.end()) len = max(len, i - mp[pre]);
		else mp[pre] = i;
	}
	return len;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	vector<int> v;
	int x;
	while (scanf("%d", &x) != EOF) v.push_back(x);
	//if (checkSubarrayWithSumZero(v)) cout << "Yes!" << endl;
	//else cout << "No!" << endl;
	cout << LongestSubarrayWithSumZero(v) << endl;
	return 0;
}