#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isOperator(const string &sym) {
        return sym == "+" || sym == "-" || sym == "*" || sym == "/";
    }
    int priority(const string &sym) {
        if (sym == "(") return 0;
        if (sym == "+" || sym == "-") return 1;
        if (sym == "*" || sym == "/") return 2;
        return 3;
    }

public:
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
};

int main() {
    freopen("in.txt", "r", stdin);
    Solution sol;
    /*
    15
    2 * 6 - ( 5 + 7 ) / ( 1 + 2 )
    33
    ( 50 + 4 * 3 / 2 + 799 - 180 + 9 + 8 + ( 3 / 3 ) + 8 + ( 9 + 3 ) / 3 )
    */
    vector<string> expression;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string temp;
        cin >> temp;
        expression.push_back(temp);
    }

    vector<string> result = sol.convertToRPN(expression);

    for (int i = 0; i < result.size(); ++i)
        cout << result[i] << " ";

    return 0;
}
