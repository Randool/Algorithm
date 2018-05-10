#include <cstdio>
#include <stack>
#include <cstring>
#include <iostream>
using namespace std;

int train[1005];

int main() {
	int N;
	while (~scanf("%d", &N), N)
	{
		while (scanf("%d", &train[1]), train[1])
		{
			for (int i=2; i<=N; ++i)
				scanf("%d", &train[i]);
			stack<int> s;
			int p = 1; // 入栈顺序
			int q = 1; // 出栈顺序
			bool flag = 1;
			// 看 p是否能够通过栈 s形成 train
			while ( q <= N )
			{
				if (p == train[q]) {	// 入栈等于train的排列，直接出栈
					++p, ++q;
				}
				else if (!s.empty() && s.top() == train[q]) { // 通过栈凑出 train的排列
					s.pop();
					q++; //测试下一届车厢
				}
				else if (p <= N) { // 前两项都不满足，只好先去栈中等待
					s.push(p++);
				}
				else {
					flag = 0;
					break;
				}
			}
			printf("%s\n", flag ? "Yes" : "No");
		}
	}
	return 0;
}
