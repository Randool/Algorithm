// http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1091
#include <bits/stdc++.h>
using namespace std;
#define M 50001

struct Line {
    int lt, rt;
    const operator < (Line l) const { return (lt == l.lt) ? rt < l.rt : lt < l.lt; }
} lines[M];

int cover(const Line &a, const Line &b) {
    if (a.rt < b.lt) return 0;
    if (a.lt == b.lt) return a.rt - a.lt;
    else return (a.rt >= b.rt) ? (b.rt - b.lt) : (a.rt - b.lt);
}

int cov_end(const Line &a, int &end) {
    if (a.rt <= end) return a.rt - a.lt;
    else if (a.lt <= end && end < a.rt) {
        int cov = end - a.lt;
        end = a.rt;
        return cov;
    } else {
        end = a.rt;
        return 0;
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int n, l, r, result = 0, end = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &l, &r);
        lines[i].lt = l;
        lines[i].rt = r;
    }
    sort(lines, lines+n);

    end = lines[0].rt;
    for (int i = 1; i < n; ++i)
        result = max(result, max(cover(lines[i-1], lines[i]), cov_end(lines[i], end)));

    printf("%d\n", result);

    return 0;
}
