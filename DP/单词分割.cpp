#include <bits/stdc++.h>
using namespace std;

class Solution {
    int getlen(string ss) { return ss.length(); }
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     * Given a string s and a dictionary of words dict, determine if s can be
     * segmented into a space-separated sequence of one or more dictionary words.
     */
    bool wordBreak(string s, set<string>& dict) {
        if (s.empty()) return true;
        if (dict.empty()) return false;

        // get the max word length of dict
        int max_len = 0;
        for (set<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
            max_len = max(max_len, getlen(*it));
        }


        vector<bool> can_break(s.size()+5, false);
        can_break[0] = true;
        for (int i = 1; i <= s.length(); ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (i - j > max_len) break;
                if (can_break[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
                    can_break[i] = true;
                    break;
                }
            }
        }
        return can_break[s.size()];
    }
};

int main()
{
    Solution sol;

    string s, tmp;
    set<string> dict;
    while (cin >> s)
    {
        dict.clear();
        cout << "numbers of set: ";
        int num;
        cin >> num;
        for (int i=0; i<num; ++i) {
            cin >> tmp;
            dict.insert(tmp);
        }
        if (sol.wordBreak(s, dict))
            puts("Yes");
        else
            puts("No");
    }

    return 0;
}
