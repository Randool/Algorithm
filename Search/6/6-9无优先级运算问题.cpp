#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

#define MAXN 50
#define abs(a) (a > 0 ? a : -a)
#define Pop(q, tar) (tar = q.top(), q.pop())

int n, target, arr[MAXN];

class Compute {
public:
    Compute() : value(0), uidx(0), unidx(n) {
        for (int i = 0; i < n; ++i) {
            unused.push_back(arr[i]);
        }
    }

    vector<int> unused, used;
    int unidx, uidx;
    int value;  // 当前计算值
    char opt[MAXN]; // 符号

    friend bool operator < (const Compute &a, const Compute &b) {
        if (a.uidx == b.uidx)
            return abs(a.value - target) > abs(b.value - target);
        else return (a.uidx > b.uidx);
	}
};

void compute_max() {
    priority_queue<Compute> pq;

    for (int i = 0; i < n; ++i) {
        Compute com;
        com.used.push_back(arr[i]);
        com.value = arr[i];
        pq.push(com);
    }

    Compute cur;
    while (!pq.empty()) {
        Pop(pq, cur);
        printf("%d\n", cur.value);
    }

}

int main() {

    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &target);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    compute_max();

    return 0;
}
