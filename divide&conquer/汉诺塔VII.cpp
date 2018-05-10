#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

// 即当前最大n不出现在“B”，中转柱上

int T, a, b, c, t, n;
int hanoi[3][64];
int num[3];

int main()
{
    // freopen("in.txt", "r", stdin);
    cin >> T;
    while (T--)
    {
        cin >> n;
        a = 0;b = 1; c = 2;
		memset(hanoi, 0, sizeof(hanoi));
		memset(num, 0, sizeof(num));
		for (int i=0; i<3; ++i) {
			cin >> num[i];
			for (int j = 0; j < num[i]; ++j) {
				cin >> t;
				hanoi[i][t-1] = 1;
			}
		}
		
		while (n--)
		{
			if (hanoi[b][n]) {
				puts("false");
				break;
			}
			if (hanoi[a][n])
				swap(b, c);
			else if (hanoi[c][n])
				swap(a, b);
		}
		
		if (n == -1)
			puts("true");
    }
    return 0;
}
/*
true
false
false
false
true
true
*/
