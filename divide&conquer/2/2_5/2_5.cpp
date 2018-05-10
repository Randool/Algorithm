#include <iostream>
#include <string>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

/**
 * recursion
 */
void permutation(string &ele, int cur, int &cnt) {
    if (cur == ele.length() - 1) {
        ++cnt;
        cout << ele << endl;
        return;
    }
    map<char, bool> mcb;
    for (int i = cur; i < ele.length(); ++i) {
        if (mcb[ele[i]]) continue;
        mcb[ele[i]] = true;
        swap(ele[i], ele[cur]);
        permutation(ele, cur+1, cnt);
        swap(ele[i], ele[cur]);
    }
}

/**
 * non-recursive
 */
bool next(string &ele) {
    int p = ele.length()-2;
    for (p; p >= 0; --p) {
        if (ele[p] < ele[p+1])
            break;
    }
    if (p < 0)
        return false;

    int q = ele.length()-1;
    for (q; q >= 0; --q) {
        if (ele[q] > ele[p])
            break;
    }
    swap(ele[p], ele[q]);
    reverse(ele.begin()+p+1, ele.end());
    return true;
}

void permutation(string &ele) {
    int cnt = 1;
    cout << ele << endl;
    while (next(ele)) {
        ++cnt;
        cout << ele << endl;
    }
    cout << cnt << endl;
}


int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, cnt=0;
    string ele;
    cin >> n;
    cin.ignore();
    getline(cin, ele);
    sort(ele.begin(), ele.end());

    //permutation(ele);

    permutation(ele, 0, cnt);
    cout << cnt << endl;

    return 0;
}
