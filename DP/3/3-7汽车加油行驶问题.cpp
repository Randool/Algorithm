#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 105
#define INF 0x7fffffff
#define cur     stMap[i][j]
#define up      stMap[i-1][j]
#define down    stMap[i+1][j]
#define lt      stMap[i][j-1]
#define rt      stMap[i][j+1]

int N, K, A, B, C;
int r[MAXN][MAXN];

struct State {
    int b_K, nb_K, no_K;
    int build, nbuild, noil;
    State() {
        b_K = nb_K = no_K = build = nbuild = noil = 0;
    }
};
State stMap[MAXN][MAXN];

void Init() { stMap[1][1].noil = K; }

void DP() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cur.
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d%d", &N, &K, &A, &B, &C);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            scanf("%d", &r[i][j]);
        }
    }

    return 0;
}
