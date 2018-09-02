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
         * ��Ϊ��֪��*��Ҫƥ����ٸ��ַ���
         * ������Ҫ���ϳ���*�Ժ���ַ�ƥ�����
         * star������¼��ǰ������*�ĺ�һ��λ��
         * point����ö��s��λ�ã��Ƚ�s��p�Ƿ�ƥ��
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
        while (p[j] == '*') // �����β��*�����
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
