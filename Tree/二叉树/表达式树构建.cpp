#include <bits/stdc++.h>
using namespace std;

class ExpressionTreeNode {
public:
    string symbol;
    ExpressionTreeNode *left, *right;
    ExpressionTreeNode(string symbol) {
        this->symbol = symbol;
        this->left = this->right = NULL;
    }
};

class Solution {
private:
    bool isnum(const string &symbol) {
        return isalnum(symbol[0]);
    }
    int priority(string opt) {
        if (opt == "(") return 0;
        if (opt == "+" || opt == "-") return 1;
        if (opt == "*" || opt == "/") return 2;
        return 3;
    }
    bool isOperator(string c) {
        return (c == "+" || c == "-" || c == "*" || c == "/");
    }
    vector<string> convertToRPN(vector<string> &expression) {
        vector<string> RPN;
        stack<string> st;
        if (expression.empty()) return RPN;

        for (int i = 0; i < expression.size(); ++i) {
            if (expression[i] == "(")
                st.push(expression[i]);
            else if (expression[i] == ")") {
                while (st.top() != "(") {
                    RPN.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            else {
                if ( !isOperator(expression[i]) )
                    RPN.push_back(expression[i]);
                else {
                    while (!st.empty() && priority(st.top()) >= priority(expression[i])) {
                        RPN.push_back(st.top());
                        st.pop();
                    }
                    st.push(expression[i]);
                }
            }
        }
        while (!st.empty()) {
            RPN.push_back(st.top());
            st.pop();
        }
        return RPN;
    }
protected:
    typedef ExpressionTreeNode Ext;
public:
    Ext *build(vector<string> &expression) {
        Ext *root = NULL;
        vector<string> rpn = convertToRPN(expression);
        if (rpn.empty()) return root;

        stack<Ext *> nodes;
        for (int i = 0; i < rpn.size(); ++i) {
            Ext *tmp = new Ext(rpn[i]);
            if (isnum(rpn[i]))
                nodes.push(tmp);
            else {
                tmp->right = nodes.top();
                nodes.pop();
                tmp->left = nodes.top();
                nodes.pop();
                nodes.push(tmp);
            }
        }
        root = nodes.top();
        nodes.pop();
        return root;
    }
};

void traverse(ExpressionTreeNode *root) {
    if (!root) return;
    traverse(root->left);
    cout << root->symbol << " ";
    traverse(root->right);
}

int main() {

    Solution sol;
    /*
    15
    2 * 6 - ( 5 + 7 ) / ( 1 + 2 )
    33
    ( 50 + 4 * 3 / 2 + 799 - 180 + 9 + 8 + ( 3 / 3 ) + 8 + ( 9 + 3 ) / 3 )
    10
    ( ( ( ( ( ) ) ) ) )
    */
    vector<string> expression;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string temp;
        cin >> temp;
        expression.push_back(temp);
    }
    ExpressionTreeNode *root = sol.build(expression);
    traverse(root);

    return 0;
}
