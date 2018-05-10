#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#include <iostream>
#define bug1 remove_BUG[p-2]
#define bug2 remove_BUG[p-1]
#define bug3 remove_BUG[p]
#define MAXN 999999
using namespace std;

char remove_BUG[MAXN];

int main()
{
    // freopen("in.txt", "r", stdin);
    string lines, line;
    while (getline(cin, line)) lines += line + '\n';
    //cout << lines;
    int p = 0, q = 0;
    int len = lines.length();
    while (true)
    {
    	if (q == lines.length()) {
    		remove_BUG[p] = '\0';
    		break;
		}
    	remove_BUG[p] = lines[q];
    	if (p >= 2 && remove_BUG[p-2] == 'B' && remove_BUG[p-1] == 'U' && remove_BUG[p] == 'G') {
    		p -= 2;
		}
		else ++p;
    	++q;
	}
	for (int i=0; i<p; ++i)
		printf("%c", remove_BUG[i]);
    return 0;
}
