#include<iostream>
#include<queue>
using namespace std;


class Stack {
private:
	queue<int> q1, q2;
public:
	void push(const int data) {
		q1.push(data);
	}
	int top() {
		while (q1.size() > 1) {
			int element = q1.front();
			q2.push(element);
			q1.pop();
		}
		int temp = q1.front();
		q1.pop();
		q2.push(temp);
		swap(q1, q2);
		return temp;
	}
	void pop() {
		if (q1.empty()) return;
		while (q1.size() > 1) {
			int element = q1.front();
			q2.push(element);
			q1.pop();
		}
		q1.pop();
		swap(q1, q2);
	}
	int size() {
		return q1.size() + q2.size();
	}
	bool empty()  {
		return this->size() == 0;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}