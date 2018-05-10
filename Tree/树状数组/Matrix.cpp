#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 1025
using namespace std;

int X, N, T, x1,x2,y1,y2;
int A[MAXN][MAXN];

void update(int x, int y, int t)
{
    while(x <= N)
    {
        int yy = y;
        while(yy <= N)
        {
            A[x][yy] += t;
            yy += yy & (-yy);
        }
        x += x & (-x);
    }
}

int getSum(int x, int y)
{
    int s = 0;
    while(x>0)
    {
        int yy = y;
        while(yy>0)
        {
            s += A[x][yy];
            yy -= yy & (-yy);
        }
        x -= x & (-x);
    }
    return s;
}

void Show(int N)
{
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main()
{
    //freopen("in.txt", "r", stdin);
    cin >> X;
    while(X--)
    {
        scanf("%d%d", &N, &T);
        memset(A, 0, sizeof(A));
        getchar();
        while(T--)
        {
            char c;
            scanf("%c", &c);
            if(c=='C')
            {
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                update(x1, y1, 1);
                update(x1, y2+1, -1);
                update(x2+1, y1, -1);
                update(x2+1, y2+1, 1);
                //Show(N);
            }
            else if(c=='Q')
            {
                scanf("%d%d", &x1, &y1);
                printf("%d\n", getSum(x1,y1)%2);
            }
            getchar();
        }
        if(T)
            printf("\n");
    }
    return 0;
}
