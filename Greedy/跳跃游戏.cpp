#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        if (A.size() == 0 || A.size() == 1) return 0;

        const int N = A.size() - 1;
        int jumps = 0, end = N, min_index = N;

        while (end > 0) {
            for (int i=end-1; i>=0; --i)
                if (i + A[i] >= end)
                    min_index = i;

            if (min_index < end) {
                ++jumps;
                end = min_index;
            }
            else return -1;
        }

        return jumps;
    }
};

int main()
{
    vector<int> A;
    int n, t;
    while (cin >> n) {
        for (int i=0; i<n; ++i)
            cin >> t, A.push_back(t);
        cout << sol.jump(A) << endl;
    }
    return 0;
}
