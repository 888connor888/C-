#include<iostream>
#include<cstring>
#include<queue>
#include<unordered_map>
using namespace std;

void First_uniqueChar(string s) {
	unordered_map<char, int> mp;
	queue<char> qu;
	for (int i = 0; i < s.length(); i++) {
		qu.push(s[i]);
		mp[s[i]]++;
		if (!qu.empty() and mp[qu.front()] > 1) qu.pop();
	}
	while (!qu.empty() and mp[qu.front()] > 1)
		qu.pop();
	cout << qu.front();
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	string s;
	cin >> s;
	First_uniqueChar(s);
	return 0;
}