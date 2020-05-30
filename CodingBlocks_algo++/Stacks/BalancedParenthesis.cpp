#include<iostream>
#include<stack>
using namespace std;

bool checkExpression(string str) {
	stack<char> s;
	for (int i = 0; i < str.length(); i++) {
		char x = str[i];
		if (x == '(' or x == '{' or x == '[') {
			s.push(x);
		}
		else if (x == ')') {
			if (s.empty() or s.top() != '(' )  return false;
			s.pop();
		}
		else if (x == '}') {
			if (s.empty() or s.top() != '{' )  return false;
			s.pop();
		}
		else if (x == ']') {
			if (s.empty() or s.top() != '[' )  return false;
			s.pop();
		}
	}
	return s.empty();
}

int main() {
	string str;
	cin >> str;
	bool x = checkExpression(str);
	if (x) cout << "Yes" << endl;
	else  cout << "No" << endl;
	return 0;
}