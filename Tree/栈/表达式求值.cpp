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
    int str2int(const string &str) {
        int ans = 0;
        for (int i = 0; i < str.size(); ++i)
            ans = ans*10 + str[i]-48;
        return ans;
    }
    vector<string> convertoRPN(const vector<string> &exp) {
        vector<string> RPN;
        stack<string> st;
        if (exp.empty()) return RPN;

        for (int i = 0; i < exp.size(); ++i) {
            if (exp[i] == "(") st.push(exp[i]);
            else if (exp[i] == ")") {
                while (st.top() != "(") {
                    RPN.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            else {
                if ( !isOperator(exp[i]) )
                    RPN.push_back(exp[i]);
                else {
                    while ( !st.empty() && priority(st.top()) >= priority(exp[i])) {
                        RPN.push_back(st.top());
                        st.pop();
                    }
                    st.push(exp[i]);
                }
            }
        }
        while (!st.empty()) {
            RPN.push_back(st.top());
            st.pop();
        }
        return RPN;
    }

public:
    int evaluateExpression(vector<string> &expression) {
        if (expression.empty()) return 0;
        vector<string> RPN = convertoRPN(expression);
        if (RPN.empty()) return 0;
        stack<int> cal;

        for (int i = 0; i < RPN.size(); ++i) {
            if (!isOperator(RPN[i]))
                cal.push(str2int(RPN[i]));
            else {
                int second = cal.top();
                cal.pop();
                int first = cal.top();
                cal.pop();
                int temp;
                if (RPN[i] == "+") temp = first + second;
                else if (RPN[i] == "-") temp = first - second;
                else if (RPN[i] == "*") temp = first * second;
                else if (RPN[i] == "/") temp = first / second;
                cal.push(temp);
            }
        }
        return cal.top();
    }
};

int main() {
    //freopen("in.txt", "r", stdin);
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

    cout << sol.evaluateExpression(expression) << endl;

    return 0;
}
