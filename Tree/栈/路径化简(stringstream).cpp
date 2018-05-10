#include <bits/stdc++.h>
using namespace std;

// /home/            /home
// /a/./b/../../c/   /c
// /../              /
// /home//temp/      /home/temp

class Solution {
public:
    string simplifyPath(string &path) {
        vector<string> dirs;
        for (string::iterator i = path.begin(); i != path.end(); )
        {
            ++i;
            string::iterator j = find(i, path.end(), '/');
            string dir = string(i, j);
            if (!dir.empty() && dir != ".") {
                if (dir == "..") {
                    if (!dirs.empty())
                        dirs.pop_back();
                }
                else dirs.push_back(dir);
            }
            i = j;
        }
        stringstream result;
        if (dirs.empty())
            result << "/";
        else {
            for (vector<string>::iterator it = dirs.begin(); it != dirs.end(); ++it)
                result << '/' << *it;
        }
        return result.str();
    }
};

int main() {
    Solution sol;
    string path;
    while (cin >> path)
        cout << sol.simplifyPath(path) << endl;

    return 0;
}
