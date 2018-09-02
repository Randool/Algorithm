#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param s: A string
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        /**
         * 因为不知道*需要匹配多少个字符，
         * 所以需要不断尝试*以后的字符匹情况。
         * star用来记录当前遇到的*的后一个位置
         * point用来枚举s的位置，比较s和p是否匹配
         */
        int i = 0, j = 0, star = 0, point = 0;
        while (s[i]) {
            if (s[i] == p[j] || p[j] == '?') {
                ++i, ++j;
            }
            else if (p[j] == '*') {
                star = ++j;
                point = i;
            }
            else if (star) {
                i = ++point;
                j = star;
            }
            else {
                return false;
            }
        }
        while (p[j] == '*') // 处理结尾有*的情况
            ++j;
        return !p[j];
    }
};
/*
aacabacd
a*acd

aaaaaaad
*a
*/

int main()
{
    Solution sol;
    char s[1024];
    char p[1024];
    scanf("%s%s", s, p);
    if (sol.isMatch(s, p))
        puts("True");
    else
        puts("False");
	return 0;
 }
