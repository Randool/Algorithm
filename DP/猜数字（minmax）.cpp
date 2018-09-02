#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    vector<vector<int> > note;
    int dp(int p, int q) {
        if (q <= p) return 0;
        if (p+1 == q) return p;
        if (note[p][q]) return note[p][q];
        int result = INT_MAX;
        for (int i = p; i <= q; ++i) {
            result = min( result, i + max(dp(p, i-1), dp(i+1, q)) );
        }
        return (note[p][q] = result);
    }
public:
    int getMoneyAmount(int n) {
        note = vector<vector<int> > (n+2);
        for (int i = 0; i < n+2; ++i)
            note[i].resize(n+2);
        int result = dp(1, n);
        return result;
    }
};

int main() {
    Solution sol;
    cout << sol.getMoneyAmount(4) << endl;

    return 0;
}
