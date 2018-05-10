#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    double myPow_(double x, int n) {
        if (!n) return 1.0;
        double ans = 1.0;
        double half = myPow_(x, n>>1);
        if (n & 1) ans = half * half * x;
        else ans = half * half;
        return ans;
    }
public:
    double myPow(double x, int n) {
        if (n < -6000) return 0.00000;
        if (n < 0) return 1.0 / myPow_(x, -n);
        else return myPow_(x, n);
    }
};

int main() {
    Solution sol;
    printf("%0.8llf\n",sol.myPow(2.0, -2147483648));
    return 0;
}
