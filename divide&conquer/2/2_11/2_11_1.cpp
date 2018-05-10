#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
#define ll long long
#define MAXN 100001

ll int Ans[MAXN];
ll int solve(int n){
    if(n < 100000 && Ans[n]!=0) return Ans[n];
    ll ans = 1;
    for(int i = 2; i <= sqrt(n); ++i){
        if(n % i == 0){
            ans+=solve(n/i);
            if(i*i==n) break;
            ans+=solve(i);
        }
    }
    if(n < 100000) Ans[n] = ans;
    return ans;
}
int main(){
    int n;
    scanf("%d",&n);
    memset(Ans,0,sizeof(Ans));
    Ans[1] = Ans[2] = Ans[3] = 1;
    printf("%lld", solve(n));
    return 0;
}
