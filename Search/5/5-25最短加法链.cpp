#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 55

int target, item, minLen;
int chain[MAXN], result[MAXN];

void Len(int cur) {
    if (cur >= minLen) return;  // ºÙ÷¶
    for (int i = 1; i <= cur; ++i) {
        chain[cur+1] = chain[cur] + chain[i];
        if (chain[cur+1] > target) return;  // ºÙ÷¶
        if (chain[cur+1] == target) {
            if (cur < minLen) {
                minLen = cur+1;
                memcpy(result, chain, sizeof(chain));
            }
        }
        Len(cur+1);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    // FILE *fi = fopen("input.txt", "r");
    while (~scanf("%d", &target)) {
        if (!target) break;
        else if (target == 1)  printf("%d\n", 1);
        else {
            item = 1;
            minLen = MAXN;
            chain[item] = 1;

            Len(1);
            //printf("%d\n", minLen-1);
            for (int i = 1; i <= minLen; ++i)
                printf("%d ", result[i]);
            printf("\n");
        }
    }

    return 0;
}
