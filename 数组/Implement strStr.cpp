// http://www.lintcode.com/en/problem/strstr/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> next;
    void makeNext(const char *target) {
        int len = strlen(target), i = 0;
        next = vector<int> (len+5);
        int j = next[0] = -1;
        while (i <= len) {
            if (j < 0 || target[i] == target[j]) {
                ++i, ++j;
                next[i] = target[i] != target[j] ? j : next[j];
            }
            else
                j = next[j];
        }
    }
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        if (source == NULL || target == NULL) return -1;
        int n = strlen(source), i = 0;
        int m = strlen(target), j = 0;
        if (m > n) return -1;
        if (!m) return 0;
        makeNext(target);
        while (i <= n && j < m)
            if (j < 0 || source[i] == target[j])
                ++i, ++j;
            else j = next[j];
        return i-j >= n ? -1 : i-j;
    }
};
/*
aabcbabcaabcaababc abcaababc
AVERDXIVYERDIAN VERDI
abcdabcdefg bcd
source rced
*/
int main()
{
    char source[100], target[100];
    while(~scanf("%s%s", source, target)) {
        Solution sol;
        int Move = sol.strStr(source, target);
        if (Move >= 0) {
            printf("%s\n", source);
            for (int i = 0; i < Move; ++i) printf(" ");
            printf("%s\n", target);
        }
        else {
            printf("-1\n");
        }
    }
    return 0;
}
