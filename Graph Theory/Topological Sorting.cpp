#include <bits/stdc++.h>
#define MAXN 505
using namespace std;


struct DirectedGraphNode
{
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};

class Solution {
private:
    DirectedGraphNode* cur = NULL, *next = NULL;

    void get_degree(vector<DirectedGraphNode*> &graph, map<DirectedGraphNode*, int> &indegree) {
        for (int i=0; i<graph.size(); ++i) {
            cur = graph[i];
            for (int j=0; j<cur->neighbors.size(); ++j) {
                next = cur->neighbors[j];
                indegree[cur] += 1;
            }
        }
    }

public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph)
    {
        vector<DirectedGraphNode*> result;
        if (graph.size() == 0) return result;

        map<DirectedGraphNode*, int> indegree;
        get_degree(graph, indegree);

        queue<DirectedGraphNode*> Q;
        for (int i=0; i<graph.size(); ++i) {
            cout << graph[i]->label << endl;
            if (indegree[graph[i]] == 0) {
                result.push_back(graph[i]);
                Q.push(graph[i]);
            }
        }

        while ( !Q.empty() )
        {
            cur = Q.front(), Q.pop();
            for (int i=0; i<cur->neighbors.size(); ++i)
            {
                next = cur->neighbors[i];
                indegree[next] -= 1;
                if (indegree[next] == 0)
                {
                    result.push_back(next);
                    Q.push(next);
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<DirectedGraphNode*> vec, result;
    DirectedGraphNode* tmp[6];
    for (int i=0; i<6; ++i)
        tmp[i] = new DirectedGraphNode(i);
    tmp[0]->neighbors.push_back(tmp[1]);
    tmp[0]->neighbors.push_back(tmp[2]);
    tmp[0]->neighbors.push_back(tmp[3]);
    tmp[1]->neighbors.push_back(tmp[4]);
    tmp[2]->neighbors.push_back(tmp[4]);
    tmp[2]->neighbors.push_back(tmp[5]);
    tmp[3]->neighbors.push_back(tmp[4]);
    tmp[3]->neighbors.push_back(tmp[5]);

    vec.push_back(tmp[0]);

    Solution sol;
    result = sol.topSort(vec);

    for (int i=0; i<result.size(); ++i)
        cout << result[i]->label << " ";

    return 0;
}
