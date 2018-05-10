#include <bits/stdc++.h>
using namespace std;

#define lson l, mid, root<<1
#define rson mid+1, r, root<<1|1

struct Node {
    int val, rank;
};

bool cmp1(const Node &a, const Node &b) { return a.val < b.val; }
bool cmp2(const Node &a, const Node &b) { return a.rank < b.rank; }

class Solution {
private:
    vector<int> segment;
    map<int, int> cnt;

    int query(int index, int l, int r, int root) {
        if (r == index) return segment[root];
        int mid = (l+r) >> 1, ans = 0;

        if (mid < index)
            ans = segment[root<<1] + query(index, rson);
        else
            ans = query(index, lson);
        return ans;
    }

    void update(int index, int add, int l, int r, int root) {
        if (l == r) {
            segment[root] += add;
            return ;
        }
        int mid = (l+r) >> 1;
        if (index <= mid) update(index, add, lson);
        else update(index, add, rson);
        segment[root] += add; // maybe
    }
public:
    /*
     * @param A: An integer array
     * 10000
     * @return: Count the number of element before this element 'ai' is smaller than it and return count number array
     */
    vector<int> countOfSmallerNumberII(vector<int> A) {
        vector<int> result;
        if (A.empty()) return result;

        result = vector<int>(A.size());

        // Ñ¹Ëõ
        vector<Node> temp(A.size());
        for (int i = 0; i < A.size(); ++i)
            temp[i].rank = i + 1, temp[i].val = A[i];
        sort(temp.begin(), temp.end(), cmp1);

        // »¹Ô­
        int t = 1;
        int pre = temp[0].val;
        for (int i = 0; i < A.size(); ++i) {
            if (temp[i].val == pre)
                temp[i].val = t;
            else
            {
                pre = temp[i].val;
                temp[i].val = ++t;
            }
        }
        sort(temp.begin(), temp.end(), cmp2);

        segment = vector<int>(A.size()<<2, 0);

        for (int i = 0; i < A.size(); ++i) {
            result[temp[i].rank-1] = query(temp[i].val, 1, A.size(), 1) - cnt[temp[i].val];
            ++cnt[temp[i].val];
            update(temp[i].val, 1, 1, A.size(), 1);
        }
        return result;
    }
};

int main() {
    int n, t;
    int test[] = {26,78,27,100,33,67,90,23,66,5,
                  38,7,35,23,52,22,83,51,98,69,
                  81,32,78,28,94,13,2,97,3,76,
                  99,51,9,21,84,66,65,36,100,41
                 };
    vector<int> A(test, test + 40);
    Solution sol;
    vector<int> result = sol.countOfSmallerNumberII(A);
    for (int i = 0; i < result.size(); ++i) cout << setw(4) << test[i];
    cout << endl;
    for (int i = 0; i < result.size(); ++i) cout << setw(4) << result[i];
    cout << endl;
    return 0;
}
