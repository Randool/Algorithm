#include <bits/stdc++.h>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
typedef UndirectedGraphNode G;

class Solution {
protected:
    typedef UndirectedGraphNode G;
private:
    map<int, bool> vis;
    queue<G *> Q1, Q2;
public:
    G* cloneGraph(G* node) {
        if (!node) return NULL;
        G *root = new G(node->label);
        G *p1 = NULL, *p2 = NULL;

        Q1.push(node), Q2.push(root);

        while ( !Q1.empty() )
        {
            p1 = Q1.front(), Q1.pop();
            p2 = Q2.front(), Q2.pop();

            if (vis[p1->label]) continue;
            vis[p1->label] = true;

            for (int i = 0; i < p1->neighbors.size(); ++i) {
                G *nb = p1->neighbors[i];
                G *temp = new G(nb->label);

                p2->neighbors.push_back(temp);

                Q1.push(nb);
                Q2.push(temp);
            }
        }

        return root;
    }
};

int main() {
    Solution sol;

    G *root = new G(0);
    G *a = new G(1);
    a->neighbors.push_back(new G(1));
    a->neighbors.push_back(root);
    root->neighbors.push_back(root);
    root->neighbors.push_back(root);
    root->neighbors.push_back(a);

    G *_root = sol.cloneGraph(root);
    queue<G *> Q;
    map<int, bool> vis;
    Q.push(_root);
    while (!Q.empty()) {
        G *temp = Q.front();
        Q.pop();
        if (vis[temp->label]) continue;
        vis[temp->label] = true;
        cout << temp->label << " : ";

        for (int i = 0; i < temp->neighbors.size(); ++i) {
            cout << temp->neighbors[i]->label << " ";
            Q.push(temp->neighbors[i]);
        }
        cout << endl;
    }

    return 0;
}
