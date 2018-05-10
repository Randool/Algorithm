#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isnum(char c) {
        return c <= '9' && c >= '0';
    }
    int trans(string ss) {
    	int ans = 0;
    	for (int i=0; i<ss.length(); ++i)
    		ans = ans * 10 + ss[i] - '0';
    	return ans;
	}
public:
    /**
     * @param s  an expression includes numbers, letters and brackets
     * @return a string
     */
    string expressionExpand(string& s) {
    	if (s.empty()) return "";
        for (int i = 0; i < s.length(); ++i)
        {
        	if (isnum(s[i]))
        	{
        		int jump = 0, t = i;
        		while (isnum(s[t++])) ++jump;
        		int cnt = 0;
        		int times = trans(s.substr(i, jump));
        		cout << times << endl;
        		for (int j = i+1; j < s.length(); ++j)
        		{
        			if (s[j] == '[') ++cnt;
        			else if (s[j] == ']' && cnt != 1) --cnt;
        			else if (s[j] == ']' && cnt == 1)
					{
        				string temp = s.substr(i+2+jump, j-i-2);
        				int len_cur = temp.length();
						temp = expressionExpand(temp);
						cout << "add this : " << temp << endl;
        				int len_then = temp.length();
        				cout << "remove this : " << s.substr(i+jump, j-i-jump+1) << endl;
        				s.erase(i, j-i+1);
        				while (times--) s.insert(i, temp);
						i += len_then - len_cur;
						break;
					}
				}
			}
		}
        return s;
    }
};
/*
abc3[a]
3[abc]
4[ac]dy
3[2[ad]3[pf]]xyz
1[lie]4[abcAhj]
1[lie]4[abcAhj]4[wer]0[peer]
5[10[abcd]Ac20[abcde]]
*/
int main()
{
    string s;
    Solution sol;
    while (cin >> s)
        cout << sol.expressionExpand(s) << endl;
    return 0;
}
