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
			int p = 1; // ��ջ˳��
			int q = 1; // ��ջ˳��
			bool flag = 1;
			// �� p�Ƿ��ܹ�ͨ��ջ s�γ� train
			while ( q <= N )
			{
				if (p == train[q]) {	// ��ջ����train�����У�ֱ�ӳ�ջ
					++p, ++q;
				}
				else if (!s.empty() && s.top() == train[q]) { // ͨ��ջ�ճ� train������
					s.pop();
					q++; //������һ�쳵��
				}
				else if (p <= N) { // ǰ��������㣬ֻ����ȥջ�еȴ�
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
