#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
private:
    void Build_tree(vector<int> &A, vector<long long> &segment, int start, int end, int root) {
        if (start == end) {
            segment[root] = (long long)A[start-1];
            return ;
        }
        int mid = (start + end) >> 1;

        Build_tree(A, segment, start, mid, root<<1);
        Build_tree(A, segment, mid+1, end, root<<1|1);

        segment[root] = segment[root<<1] + segment[root<<1|1];
    }

    long long query(vector<long long> &segment, int start, int end, int l, int r, int root) {
        if (start <= l && r <= end)
            return segment[root];

        int mid = (l + r) / 2;

        long long left = 0, right = 0;

        if (end <= mid)
            left = query(segment, start, end, l, mid, root<<1);
        else if (start > mid)
            right = query(segment, start, end, mid+1, r, root<<1|1);
        else {
            left = query(segment, start, end, l, mid, root<<1);
            right = query(segment, start, end, mid+1, r, root<<1|1);
        }

        return left + right;
    }

public:
    vector<long long> intervalSum(vector<int> A, vector<Interval> queries) {
        vector<long long> result;
        if (A.empty() || queries.empty()) return result;

        vector<long long> segment(A.size() << 2);
        Build_tree(A, segment, 1, A.size(), 1);

        for (int i = 0; i<queries.size(); ++i)
            result.push_back(query(segment, queries[i].start+1, queries[i].end+1, 1, A.size(), 1));

        return result;
    }
};
/*
5 3
1 2 7 8 5
0 4 1 2 2 4
*/
int main()
{
    Solution sol;
    int n, m, t, a, b;
    while (cin >> n >> m)
    {
        vector<int> A;
        vector<Interval> queries;

        for (int i = 0; i < n; ++i) cin >> t, A.push_back(t);
        for (int i = 0; i < m; ++i) cin >> a >> b, queries.push_back(Interval(a, b));

        vector<long long> result = sol.intervalSum(A, queries);

        for (int i = 0; i < m; ++i) cout << result[i] << endl;
    }

    return 0;
}
