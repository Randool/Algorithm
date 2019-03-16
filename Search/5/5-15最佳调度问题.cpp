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
int tasks[MAXN];    // ����ʱ��
int machines[MAXN]; // ��������ʱ��

/// ��ʱ����
LARGE_INTEGER BegainTime;
LARGE_INTEGER EndTime;
LARGE_INTEGER Frequency;

int cost = INF;

int greedy_sche() {
    /**
     * ʹ��̰���㷨��ȡ�ϺõĽ�
     * �����Լ��ٻ��ݵĹ���
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
     * �����㷨������
     */
    if (cur == n) {
        ++times;
        cost = min(cost, getCost());
        // printf("%d\n", cost);   // �鿴��ǰ����
        return;
    }
    else {
        for (int i = 0; i < k; ++i) {
            machines[i] += tasks[cur];
            if (getCost() < cost)   // ���ƽ���
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

    printf("�򵥻�������\n");
    printf("���: %d | ��������: %d | ����ʱ��: %lf s\n", cost, times, tictoc);
}

void optimized_backtrack() {
    times = 0;
    cost = INF;

    QueryPerformanceFrequency(&Frequency);
    QueryPerformanceCounter(&BegainTime);

    cost = greedy_sche();   /// ����̰���㷨��ý��Ž�
    memset(machines, 0, sizeof(machines));
    printf("̰�ģ�%d\n", cost);
    backtrack_sche(0);

    QueryPerformanceCounter(&EndTime);

    double tictoc = (double)(EndTime.QuadPart - BegainTime.QuadPart) / Frequency.QuadPart;

    printf("̰���Ż���������\n");
    printf("���: %d | ��������: %d | ����ʱ��: %lf s\n", cost, times, tictoc);
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
