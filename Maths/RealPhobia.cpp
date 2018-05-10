#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define inf 0x7fffffff
typedef long long LL;
using namespace std;

string rational;
int N, a, b, c, d, C, D;
float diff, tmp;

int trans_to_num(string a) {
    int ans = 0;
    for (int i=0; i<a.length(); ++i)
        ans = ans * 10 + a[i] - '0';
    return ans;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &N);
    while (N--)
    {
        cin >> rational;
        int dev = find(rational.begin(), rational.end(), '/') - rational.begin();
        a = trans_to_num(rational.substr(0,dev));
        b = trans_to_num(rational.substr(dev+1));
        //printf("%d %d\n", a, b);

        float min_ = inf;
        for (int i=b-1; i>=2; --i)  // Find d
        {
            // Get range
            tmp = 1.0 * a / b * i;
            for (int j=int(tmp); j<=int(tmp)+1; ++j)
            {
                diff = abs(1.0 * a/b - 1.0 * j/i);
                if (diff < min_) {
                    C = j, D = i;
                    min_ = diff;
                }
            }
        }
        printf("%d/%d\n", C, D);
    }
    return 0;
}
