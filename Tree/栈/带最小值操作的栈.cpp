#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
	stack<int> real, min_ele;
	int cur;
public:
    MinStack() {
        while (!real.empty()) real.pop();
        while (!min_ele.empty()) min_ele.pop();
    }

    void push(int number) {
        real.push(number);

        if (min_ele.empty()) {
            min_ele.push(number);
        }
        else {
			cur = number > min_ele.top() ? min_ele.top() : number;
            min_ele.push(cur);
        }
    }

    int pop() {
        min_ele.pop();
        cur = real.top();
        real.pop();
        return cur;
    }

    int min() {
        if (!real.size()) return 0;
        cur = min_ele.top();
        return cur;
    }
};

#define push(n) msk.push(n)
#define pop() cout << msk.pop() << endl
#define min() cout << msk.min() << endl

int main()
{
	MinStack msk;
	push(1), pop(), push(2), push(3), min(), push(1), min();

	return 0;
}
