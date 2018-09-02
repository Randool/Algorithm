// http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1873
#include <bits/stdc++.h>
using namespace std;

string mult(string a, string b) {
    int num[250], len = a.length() + b.length();
    memset(num, 0, sizeof(num));
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < a.length(); ++i)
        for (int j = 0; j < b.length(); ++j)
            num[i+j] += (a[i]-'0') * (b[j]-'0');

    for (int i = 0; i < len; ++i) {
        num[i+1] += num[i] / 10;
        num[i] %= 10;
    }

    string result = string(len, '0');

    for (int i = 0; i < len; ++i)
        result[i] += num[i];

    reverse(result.begin(), result.end());

    return result;
}

string str_pow(string ss, int p) {
    string result = "1";
    while (p) {
        if (p & 1) result = mult(result, ss);
        ss = mult(ss, ss);
        p >>= 1;
    }
    return result;
}

int main() {
    string a;
    int n, t;
    while (cin >> a >> n) {
        int dot = a.find('.');
        if (dot == -1) dot = 0;
        else {
            a.erase(a.begin() + dot);
            dot = (a.length()-dot)*n;
        }
        a = str_pow(a, n);
        a.insert(a.end()-dot, '.');

        for (t = 0; t < a.length(); ++t)
            if (a[t] != '0') break;
        a.erase(a.begin(), a.begin()+t);

        for (t = a.length()-1; t >= 0; --t)
            if (a[t] != '0') break;
        a.erase(a.begin()+t+1, a.end());
        if (*(a.end()-1) == '.') a.erase(a.end()-1);
        cout << a << endl;
    }
    return 0;
}
