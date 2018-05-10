#include <bits/stdc++.h>
using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	if (s1 == s2) {
        cout << "Same";
	}
	if (s1 < s2) {
        cout << "<";
	}
	if (s1 > s2) {
        cout << ">";
	}
	return 0;
}
