#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val, rank;
};

bool cmp1(const Node &a, const Node &b) { return a.val < b.val; }
bool cmp2(const Node &a, const Node &b) { return a.rank < b.rank; }

class Solution {
private:
    vector<int> segment;
    #define lson l, mid, root<<1
    #define rson mid+1, r, root<<1|1

    int query(int index, int l, int r, int root)
    {
        if (r == index) return segment[root];
        int mid = (l+r)>>1, ans;
        if (mid  < index) ans = segment[root<<1] + query(index, rson);
        if (mid >= index) ans = query(index, lson);
        return ans;
    }

    void update(int index, int add, int l, int r, int root)
    {
        if (l == r) {
            segment[root] += add;
            return ;
        }
        int mid = (l+r)>>1;
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

        // Ñ¹Ëõ
        vector<Node> temp(A.size());
        for (int i=0; i<A.size(); ++i)
            temp[i].rank = i+1, temp[i].val = A[i];
        sort(temp.begin(), temp.end(), cmp1);

        // »¹Ô­
        for (int i=0; i<A.size(); ++i)
            temp[i].val = i+1;
        sort(temp.begin(), temp.end(), cmp2);

        segment = vector<int>(A.size()<<2, 0);

        for (int i=0; i<A.size(); ++i)
        {
            result[temp[i].val] = query(temp[i].val, 1, A.size(), 1);
            update(temp[i].val, 1, 1, A.size(), 1);
        }
        return result;
    }
};

int main()
{
    int n, t;
    while (cin >> n)
    {
        vector<int> A;
        for (int i=0; i<n; ++i)
            cin >> t, A.push_back(t);
        Solution sol;
        vector<int> result = sol.countOfSmallerNumberII(A);
        for (int i=0; i<result.size(); ++i)
            cout << result[i] << " ";
    }
    return 0;
}
