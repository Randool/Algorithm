#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int maxsize;
    int BIT[20000];
public:
    inline int lowbit(int x) {
        return x & (-x);
    }

    int sum(int n) {
        int ans = 0;
        while (n) {
            ans += BIT[n];
            n -= lowbit(n);
        }
        return ans;
    }

    void update(int index, int add) {
        while (index <= maxsize) {
            BIT[index] += add;
            index += lowbit(index);
        }
    }

    vector<int> countOfSmallerNumberII(vector<int> &A) {
        vector<int> result;
        int len = A.size();
        maxsize = 10005;
        for (int i=0; i<len; ++i) {
            result.push_back(sum(A[i]));
            update(A[i]+1, 1);
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
