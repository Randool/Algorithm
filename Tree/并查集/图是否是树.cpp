#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int uni_find(int n, int *unin) {
        return (unin[n] == n) ? n : uni_find(unin[n], unin);
    }
public:
    bool validTree(int n, vector<vector<int> > &edges) {
        if (n - edges.size() > 1) return false;

        int unin[n+5];
        for (int i = 0; i < n; ++i) unin[i] = i;

        for (int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0], b = edges[i][1];
            int f1 = uni_find(a, unin), f2 = uni_find(b, unin);
            if (f1 == f2) return false;
            unin[f2] = f1;
        }
        return true;
    }
};

int main() {
    int n, m, a, b;
    vector<vector<int> > edges;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);
        edges.push_back(temp);
    }
    Solution sol;
    if (sol.validTree(n, edges)) cout << "True";
    else cout << "False";
    return 0;
}
