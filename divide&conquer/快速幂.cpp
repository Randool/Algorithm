#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        if(n==0) return 1 % b;
        if(n==1) return a % b;

        long long temp = fastPower(a,b,n/2);

        if(n & 1)
           return ((temp * temp) % b) * (a % b);
        else
           return temp * temp % b;
    }
};

int main()
{
    // a^n % b
    Solution sol;
    cout << sol.fastPower(2, 3, 31) << endl;
    cout << sol.fastPower(2, 10, 0) << endl;
    cout << sol.fastPower(31, 1, 0) << endl;
    cout << sol.fastPower(100, 1000, 1000) << endl;
    cout << sol.fastPower(27123, 5201314, 78965412) << endl;
    cout << sol.fastPower(1, 2147483647, 2147483647) << endl;
    return 0;
}
