#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int *deg;
    queue<int> Q;
    vector<int> result;
public:
    /// Ҫѧϰ�γ� 0 ����Ҫ��ѧϰ�γ� 1 ����ʾΪ[0,1]
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
������ n �Ų�ͬ�����Ͽγ�, ���Ϊ 1 �� n. ÿһ�ڿζ��г���ʱ��(�γ̳���) t �� �ڵ� d ��ر�.
�γ�Ӧ�������� t �죬�����ڵ�d���֮ǰ���, �㽫�ӵ�һ�쿪ʼ.
���� n �����Ͽγ��� pairs (t, d) ����ʾ, ����������ҵ������ϵ���������Ŀγ���.
 ע������
���� 1 <= d, t, n <= 10,000.
�㲻��ͬʱ�����ſ�.

���� [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
���� 3
�����ܹ��� 4 �ڿ�, �������������� 3 �ڿ�:
��һ, �ϵ�һ�ڿ�, ��Ҫ100��, ��������ڵ�100���������γ�, �����ڵ�101��׼������һ�ڿ�.
�ڶ�, �ϵ����ڿ�, ��Ҫ1000��, ��������ڵ�1100���ʱ��������ſ�, �����ڵ�1101��׼������һ�ڿ�.
����, �ϵڶ��ڿ�, ��Ҫ200��, ��������ڵ�1300���ʱ��������ſ�.
���ڲ����ϵ�4�ڿ�, ��Ϊ����ڵ�3300���ʱ��������ſ�, �����Ѿ������ر�������
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
