//http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1277
#include <bits/stdc++.h>
using namespace std;
#define M 100005

char S[M];
int next[M], len, prefix[M];

void build_next(const char *S) {
    int i = 0, j = next[0] = -1;
    while (i <= len) {
        if (j < 0 || S[i] == S[j])
            next[++i] = ++j;
        else j = next[j];
    }
}

int main()
{
    scanf("%s", S);
    len = strlen(S);
    build_next(S);

    for (int i = len; i>=1; --i) {
        ++prefix[i];
        prefix[next[i]] += prefix[i];
    }

    long long ans = 0;
    for (int i = 1; i <= len; ++i)
        ans = max(ans, (long long)i*prefix[i]);
    printf("%lld\n", ans);

    return 0;
}
