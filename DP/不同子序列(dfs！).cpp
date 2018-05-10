// http://www.lintcode.com/zh-cn/problem/distinct-subsequences/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int> > path, cnt;
    vector<vector<bool> > vis;

    void Show_Tree() {
        for (int i = 0; i < cnt.size(); ++i) {
            for (int j = 0; j < cnt[i].size(); ++j) {
                printf("%d ", cnt[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    void dfs(int cur, int index) {
        if (vis[cur][index]) return;
        if (cur == path.size()-1) {
            cnt[cur][index] = 1;
            vis[cur][index] = 1;
            return;
        }
        for (int i = 0; i < path[cur].size(); ++i) {
            for (int j = 0; j < path[cur+1].size(); ++j)
            {
                if (path[cur][i] < path[cur+1][j])
                {
                    if (cnt[cur+1][j] != 0) {
                        cnt[cur][i] += cnt[cur+1][j];
                        vis[cur+1][j] = 1;
                        continue;
                    }
                    else {
                        dfs(cur+1, j);
                        cnt[cur][i] += cnt[cur+1][j];
                        vis[cur+1][j] = 1;
                    }
                }
                Show_Tree();
            }
        }
    }

public:
    int numDistinct(string &S, string &T) {
        int result = 0;
        if (T.empty()) return 1;
        if (S.length() < T.length()) return 0;
        if (T.length() == 1) {
            for (int i = 0; i < S.length(); ++i)
                if (S[i] == T[0])
                    ++result;
            return result;
        }

        cnt = path = vector<vector<int> > (T.length());
        vis = vector<vector<bool> > (T.length());

        for (int i = 0; i < T.length(); ++i)
            for (int j = 0; j < S.length(); ++j)
                if (T[i] == S[j])
                    path[i].push_back(j), cnt[i].push_back(0), vis[i].push_back(0);
        dfs(0, 0);

        Show_Tree();

        for (int i = 0; i < cnt[0].size(); ++i)
            result += cnt[0][i];

        return result;
    }
};
/*
conatrtraa contra
6
ctrtraar ctra
*/
int main()
{
    Solution sol;
    string s, t;
    while (cin >> s >> t) {
        cout << sol.numDistinct(s, t) << endl;
    }

    return 0;
}
