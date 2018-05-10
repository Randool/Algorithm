#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    static bool mycmp(vector<int> &a, vector<int> &b) {
        return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]);
    }
public:
    /// Target : 在选择课程的时候，结束时间最早的优先选择
    int scheduleCourse(vector<vector<int> > &c) {
        int dead = 0;
        sort(c.begin(), c.end(), mycmp);
        priority_queue<int> pq;

        for (int i = 0; i < c.size(); ++i) {
            if (dead + c[i][0] <= c[i][1]) {
                dead += c[i][0];
                pq.push(c[i][0]);
            }
            else if (c[i][0] < pq.top()) {
                dead += c[i][0] - pq.top();
                pq.pop();
                pq.push(c[i][0]);
            }
        }
        return pq.size();
    }
};

int main () {
    int n, a, b;
    cin >> n;
    vector<vector<int> > courses;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        vector<int> tmp;
        tmp.push_back(a);
        tmp.push_back(b);
        courses.push_back(tmp);
    }
    Solution sol;
    cout << sol.scheduleCourse(courses) << endl;
    return 0;
}
