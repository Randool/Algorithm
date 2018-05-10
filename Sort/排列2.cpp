#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
    char a, b, c, d, cur, lst;
    int fst = 1;
    while (~scanf("%c %c %c %c", &a, &b, &c, &d))
    {
    	if (a+b+c+d - 4*'0' == 0) break;
        getchar();
        
		if (fst) fst = 0;
		else cout << endl << endl;

        string tmp;
        tmp += a; tmp += b; tmp += c; tmp += d;
        sort(tmp.begin(), tmp.end());
        lst = tmp[3];
        vector<string> result;
        result.push_back(tmp);

        while (next_permutation(tmp.begin(), tmp.end())) {
            if (tmp[0] == '0') continue;
            result.push_back(tmp);
        }

		if (result[0][0] == '0') result.erase(result.begin());

		cur = result[0][0];

		cout << result[0];
		for (int i = 1; i < result.size(); ++i) {
			if (cur != result[i][0]) {
				cur = result[i][0];
				cout << endl << result[i];
			}
			else cout << " " << result[i];
		}
		
    }
	//cout << "|";
    return 0;
}

