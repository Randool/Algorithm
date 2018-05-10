#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
private:
    TreeNode *result = NULL;
    bool isSameTree(TreeNode* T1, TreeNode* T2)
    {
        if (T1 == NULL && T2 == NULL) return 1;
        if (T1 == NULL || T2 == NULL) return 0;
        if (T1->val != T2->val) return 0;
        return isSameTree(T1->left, T2->left) && isSameTree(T1->right, T2->right);
    }
public:
    void Init() { result = NULL; }
    TreeNode* buildTree(vector<int> vec)
    {
        int cnt = 0;
        TreeNode *cur = NULL;
        queue<TreeNode*> s;
        s.push(result);
        while (!s.empty() && cnt!= vec.size())
        {
        	int size = s.size(); 
            for (int i=0; i<size; ++i)
            {
                if (vec[cnt] != 0x7fffffff) {
                    cur = s.front();
                    s.pop();
                    cur = new TreeNode(vec[cnt]);
                    s.push(cur->left);
                    s.push(cur->right);
                }
                else
                {
                    s.pop();
                }
                ++cnt;
            }
        }
        return result;
    }
    bool isSubtree(TreeNode *T1, TreeNode *T2)
    {
        if (T2 == NULL) return 1;
        else if (T1 == NULL) return 0;
        else return isSameTree(T1, T2) || isSameTree(T1->left, T2) || isSameTree(T1->right, T2);
    }
};

/*
1,#,2,#,3,#,4,#,5,#,6,#,7,#,8,#,9,#,10
4,#,5,#,6,#,7,#,8,#,9,#,10
*/
int main()
{
    Solution sol, sol1,sol2;
    string line;
    vector<int> vec;

    getline(cin, line);
    for (int i=0; i<line.length(); i+=2) {
        if (isalnum(line[i]))
            vec.push_back(line[i]-'0');
        else
            vec.push_back(0x7fffffff);
    }
    TreeNode* A = sol1.buildTree(vec);
    vec.clear();
    getline(cin, line);
    for (int i=0; i<line.length(); i+=2) {
        if (isalnum(line[i]))
            vec.push_back(line[i]-'0');
        else
            vec.push_back(0x7fffffff);
    }
    TreeNode* B = sol2.buildTree(vec);
    if (sol.isSubtree(A, B))
        puts("Same");
    else
        puts("Not Same");
    return 0;
}
