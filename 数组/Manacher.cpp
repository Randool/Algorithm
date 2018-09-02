#include <bits/stdc++.h>
using namespace std;
#define MX 100005

char s[MX << 1];
int p[MX << 1];

void Manacher(char *s) {
    int len = strlen(s), id = 0, maxlen = 0;
    for (int i = len; i >= 0; --i) {
        s[i*2+2] = s[i];
        s[i*2+1] = '#';
    }
    s[0] = '*';
    for (int i = 2; i <= len*2; ++i) {
        if (p[id] + id <= i) p[i] = 1;
        else p[i] = min(p[id*2-i], p[id] + id - i);

        while (s[i-p[i]] == s[i+p[i]]) ++p[i];

        if (id + p[id] < i + p[i])
            id = i;
        if (maxlen < p[i])
            maxlen = p[i];
    }
    cout << maxlen - 1 << endl;
    printf("%s\n", s);
}

int main() {
    while (scanf("%s", s) != EOF)
        Manacher(s);
    return 0;
}
