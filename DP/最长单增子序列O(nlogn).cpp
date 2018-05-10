/*logn是由于使用了二分查找*/
#include <cstdio>
#include <algorithm>
#define inf 0x3f3f3f3f
const int MAXN = 50005;
using namespace std;

int s[MAXN];
int new_s[MAXN];
int main()
{
    int N, ans=1;
    scanf("%d",&N);
    fill(new_s,new_s+N+5,inf); //STL中的 fill函数，类似 memset
    for(int i=0; i<N; i++) scanf("%d",&s[i]);
    for(int i=0; i<N; i++)
    {
        //upper_bound函数返回一个非递减序列[first, last)中第一个大于val的位置
        int pos = upper_bound(new_s, new_s+N+1, s[i]) - new_s;
        new_s[pos] = s[i];
        if(pos > ans) ans = pos;

        for(int i=0; i<N; i++)
            printf("%d ",new_s[i]);
        printf("\n");
    }
    printf("\n%d\n", ans+1);
    return 0;
}
