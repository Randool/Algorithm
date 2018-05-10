#include <cstdio>
#include <vector>
using namespace std;

#define MAXN 5005

int num, max_d, d, t, fa, cnt;

struct Node {
    int fa, dist;
    Node(int father=0, int distance=0) {
        fa = father, dist = distance;
    }
} root, nodes[MAXN];

vector<int> leaves;

int main() {
    FILE *fi = fopen("input.txt", "r");
    FILE *fo = fopen("output.txt", "w");

    fscanf(fi, "%d", &num);
    for (int i = 1; i <= num; ++i) {
        fscanf(fi, "%d", &t);
        if (!t) {
            leaves.push_back(i);
            continue;
        }
        while (t--) {
            fscanf(fi, "%d %d", &fa, &d);
            nodes[i].fa = id;
            nodes[i].dist = d;
        }
    }
    fscanf(fi, "%d", &d);

    printf("%d\n", cnt);
//    fprintf(fo, "%d\n", cnt);

    return 0;
}
