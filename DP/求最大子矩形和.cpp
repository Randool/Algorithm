#include <iostream>
#include <cstring>
const int rec = 501;
using namespace std;

int r[rec][rec], sum[500], temp[501];

int maxn(int a[], int x) {	//求一维数组最大子串
    int best = 0, cur = 0;
    for (int i = 0; i <= x; ++i) {
        if (cur < 0) cur = 0;
        cur += a[i];
        best = cur > best ? cur : best;
    }
    return best;
}

int main()
{
    int x, y, i, j, max, Max;
    cin >> x >> y;
    bool all_neg = 1;
    memset(r, 0, sizeof(r));
    for (i = 1; i <= y; i++)
        for (j = 1; j <= x; j++) {
            cin >> r[j][i];
            if (r[j][i]>=0) all_neg = 0;
        }

    if (all_neg==1)
        cout << "0" << endl;
    else
    {
        Max = r[1][1];
        //将二维转位多个一维数组，取其中最大子串
        for (i = 1; i <= y; i++)
        {
            for (j = i; j <= y; j++)
            {
                memset(temp, 0, sizeof(temp));
                for (int p = 1; p <= x; p++)
                    for (int q = i; q<=j; q++)
                        temp[p] = (q == i) ? r[p][q] : (temp[p] + r[p][q]);
                max = maxn(temp, x);
                if(Max < max) Max = max;
            }
        }
        cout << Max << endl;
    }
    return 0;
}
