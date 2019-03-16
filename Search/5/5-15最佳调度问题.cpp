#include <cstdio>
#include <cstring>
#include <functional>
#include <algorithm>
#include <windows.h>
using namespace std;

#define MAXN 55
#define INF 0x3fffffff

#define loop(i, a, b) for(int i = a; i < b; ++i)

int n, k, times = 0;
int tasks[MAXN];    // 任务时间
int machines[MAXN]; // 机器工作时间

/// 测时数据
LARGE_INTEGER BegainTime;
LARGE_INTEGER EndTime;
LARGE_INTEGER Frequency;

int cost = INF;

int greedy_sche() {
    /**
     * 使用贪心算法获取较好的解
     * ，可以加速回溯的过程
     */
    int greedy_result = 0;
    sort(tasks, tasks+n, greater<int>());
    memset(machines, 0, sizeof(machines));
    for (int i = 0; i < n; ++i) {
        int m = INF, idx = 0;
        for (int j = 0; j < k; ++j) {
            if (machines[j] < m) {
                m = machines[j], idx = j;
            }
        }
        machines[idx] += tasks[i];
    }
    for (int i = 0; i < k; ++i)
        greedy_result = max(greedy_result, machines[i]);

    return greedy_result;
}

int getCost() {
    int tmp = 0;
    loop(i, 0, k) tmp = max(tmp, machines[i]);
    return tmp;
}

void backtrack_sche(int cur) {
    /**
     * 回溯算法求最优
     */
    if (cur == n) {
        ++times;
        cost = min(cost, getCost());
        // printf("%d\n", cost);   // 查看当前最优
        return;
    }
    else {
        for (int i = 0; i < k; ++i) {
            machines[i] += tasks[cur];
            if (getCost() < cost)   // 限制界限
                backtrack_sche(cur+1);
            machines[i] -= tasks[cur];
        }
    }
}

void pure_backtrack() {
    times = 0;
    cost = INF;

    QueryPerformanceFrequency(&Frequency);
    QueryPerformanceCounter(&BegainTime);

    memset(machines, 0, sizeof(machines));
    backtrack_sche(0);

    QueryPerformanceCounter(&EndTime);

    double tictoc = (double)(EndTime.QuadPart - BegainTime.QuadPart) / Frequency.QuadPart;

    printf("简单回溯搜索\n");
    printf("结果: %d | 搜索次数: %d | 搜索时间: %lf s\n", cost, times, tictoc);
}

void optimized_backtrack() {
    times = 0;
    cost = INF;

    QueryPerformanceFrequency(&Frequency);
    QueryPerformanceCounter(&BegainTime);

    cost = greedy_sche();   /// 调用贪心算法获得较优解
    memset(machines, 0, sizeof(machines));
    printf("贪心：%d\n", cost);
    backtrack_sche(0);

    QueryPerformanceCounter(&EndTime);

    double tictoc = (double)(EndTime.QuadPart - BegainTime.QuadPart) / Frequency.QuadPart;

    printf("贪心优化回溯搜索\n");
    printf("结果: %d | 搜索次数: %d | 搜索时间: %lf s\n", cost, times, tictoc);
}

int main() {
    freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tasks[i]);
    }

    pure_backtrack();
    optimized_backtrack();

    return 0;
}
