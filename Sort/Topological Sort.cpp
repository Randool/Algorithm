#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int *deg;
    queue<int> Q;
    vector<int> result;
public:
    /// 要学习课程 0 你需要先学习课程 1 ，表示为[0,1]
    bool canFinish(int num, vector<pair<int, int> > &c) {
        if (num == 0) return true;
        deg = new int[num+5] ();
        vector<int> nodes[num+5];
        for (int i = 0; i < c.size(); ++i) {
            int fst = c[i].second, scd = c[i].first;
            nodes[fst].push_back(scd);
            deg[scd] += 1;
        }
        for (int i = 0; i < num; ++i)
            if (deg[i] == 0) Q.push(i);
        if (Q.empty()) return false;

        while (!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            for (int i = 0; i < nodes[cur].size(); ++i) {
                int next = nodes[cur][i];
                deg[next] -= 1;
                if (deg[next] == 0)
                    Q.push(next);
            }
            nodes[cur].clear();
        }
        for (int i = 0; i < num; ++i)
            if (deg[i]) return false;

        return true;
    }

    vector<int> findOrder(int num, vector<pair<int, int> > &c) {
        if (num == 0) return result;
        deg = new int[num+5] ();
        vector<int> nodes[num+5];
        for (int i = 0; i < c.size(); ++i) {
            int fst = c[i].second, scd = c[i].first;
            nodes[fst].push_back(scd);
            deg[scd] += 1;
        }
        for (int i = 0; i < num; ++i)
            if (deg[i] == 0) Q.push(i);

        while (!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            for (int i = 0; i < nodes[cur].size(); ++i) {
                int next = nodes[cur][i];
                deg[next] -= 1;
                if (deg[next] == 0)
                    Q.push(next);
            }
            nodes[cur].clear();
            result.push_back(cur);
        }
        for (int i = 0; i < num; ++i) {
            if (deg[i]) {
                result.clear();
                break;
            }
        }
        return result;
    }

    /**
这里有 n 门不同的线上课程, 编号为 1 到 n. 每一节课都有持续时间(课程长度) t 和 在第 d 天关闭.
课程应连续持续 t 天，必须在第d天或之前完成, 你将从第一天开始.
给出 n 门线上课程用 pairs (t, d) 来表示, 你的任务是找到可以上的最大数量的课程数.
 注意事项
整数 1 <= d, t, n <= 10,000.
你不能同时上两门课.

给出 [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
返回 3
这里总共有 4 节课, 但是你最多可以上 3 节课:
第一, 上第一节课, 需要100天, 所以你会在第100天完成这个课程, 并且在第101天准备上下一节课.
第二, 上第三节课, 需要1000天, 所以你会在第1100天的时候完成这门课, 并且在第1101天准备上下一节课.
第三, 上第二节课, 需要200天, 所以你会在第1300天的时候完成这门课.
现在不能上第4节课, 因为你会在第3300天的时候完成这门课, 但是已经超过关闭日期了
    */
    int scheduleCourse(vector<vector<int> > &courses) {
        // write your code here
    }
};

int main() {
    freopen("in.txt", "r", stdin);

    Solution sol;
    int num, m, a, b;
    vector<pair<int, int> > courses;
    cin >> num >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        courses.push_back(pair<int, int>(a, b));
    }
    vector<int> result = sol.findOrder(num, courses);
    for (int i = 0; i < result.size(); ++i)
        printf("%d ", result[i]);

    return 0;
}
