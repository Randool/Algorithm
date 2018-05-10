#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
	stack<int> stack1;
	stack<int> stack2;
	void makeQueue() {
		if (stack2.empty()) {
			while (!stack1.empty()) {
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
	}
public:
	MyQueue() {
	}

	void push(int element) {
		stack1.push(element);
	}

	int pop() {
		makeQueue();
		int temp = stack2.top();
		stack2.pop();
		return temp;
	}

	int top() {
		makeQueue();
		return stack2.top();
	}
};


int main() {
	MyQueue mq;
	mq.push(1);
	cout << mq.pop() << " ";
	mq.push(2);
	mq.push(3);
	cout << mq.top()<< " ";
	cout << mq.pop();

	return 0;
}
