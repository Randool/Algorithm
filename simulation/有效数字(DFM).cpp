#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int char2int(char c) {
        if (c == ' ') return 1;
        if (c == '+' || c == '-') return 2;
        if (c <= '9' && c >= '0') return 3;
        if (c == '.') return 4;
        if (c == 'e') return 5;
        return -1;
    }
public:
    bool isNumber(string s) {
        s += " ";
        enum state {s0, s1, s2, s3, s4, s5, s6, s7, s8};
        state cur_state = s0;

        int len = s.length(), tmp;
        for (int i = 0; i < len; ++i) {
            tmp = char2int(s[i]);
            switch (cur_state) {
                case s0: {
                    if (tmp == 1) continue;
                    else if (tmp == 2) cur_state = s1;
                    else if (tmp == 3) cur_state = s2;
                    else if (tmp == 4) cur_state = s3;
                    else return 0;
                    break;
                }
                case s1: {
                    if (tmp == 2) continue;
                    else if (tmp == 3) cur_state = s2;
                    else if (tmp == 4) cur_state = s3;
                    else return 0;
                    break;
                }
                case s2: {
                    if (tmp == 1) cur_state = s8;
                    else if (tmp == 3) continue;
                    else if (tmp == 4) cur_state = s3;
                    else if (tmp == 5) cur_state = s5;
                    else return 0;
                    break;
                }
                case s3: {
                    if (tmp == 1) cur_state = s8;
                    else if (tmp == 3) cur_state = s4;
                    else return 0;
                    break;
                }
                case s4: {
                    if (tmp == 1) cur_state = s8;
                    else if (tmp == 3) continue;
                    else if (tmp == 5) cur_state = s5;
                    else return 0;
                    break;
                }
                case s5: {
                    if (tmp == 2) cur_state = s6;
                    else if (tmp == 3) cur_state = s7;
                    else return 0;
                    break;
                }
                case s6: {
                    if (tmp == 2) continue;
                    else if (tmp == 3) cur_state = s7;
                    else return 0;
                    break;
                }
                case s7: {
                    if (tmp == 1) cur_state = s8;
                    else if (tmp == 3) continue;
                    else return 0;
                    break;
                }
                case s8: {
                    if (tmp == 1) continue;
                    else return 0;
                    break;
                }
                default: return 0;
            }
        }
        if (cur_state != s8) return 0;
        return 1;
    }
};

int main() {
    Solution sol;
    string s;
    while (getline(cin, s)) {
        if (sol.isNumber(s))
            cout << "true\n";
        else cout << "false\n";
    }

    return 0;
}
