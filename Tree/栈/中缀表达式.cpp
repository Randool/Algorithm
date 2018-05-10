#include <cstdio>
#include <cstring>
#include <stack>
#include <map>
#include <cmath>
#include <iostream>
#define MAXN 505
using namespace std;

char rep[MAXN];
stack <int> s1;
stack<char> s2;
map<char, int> pri;

void Init() {
    while ( !s1.empty() ) s1.pop();
    while ( !s2.empty() ) s2.pop();
    pri['('] = 3, pri[')'] = 3;
    pri['^'] = 2;
    pri['*'] = 1, pri['/'] = 1, pri['%'] = 1;
    pri['+'] = 0, pri['-'] = 0;
}

int cal(int a, int b, char d) {
    switch (d) {
    case '+' :
        return a + b;
    case '-' :
        return a - b;
    case '*' :
        return a * b;
    case '/' :
        return a / b;
    case '%' :
        return a % b;
    case '^' :
        return pow(a, b);
    }
}

void Infixation(char* rep) {
    for (int i=0; i<strlen(rep); ++i)
    {
        if (isalnum(rep[i]))
            s1.push(rep[i]);
        else
        {
            if (s2.empty || pri[rep[i]] < pri[s2.top()])
            {
                while ( !s2.empty() ) {
                    if (s2.top() == '(') break;
                    s1.push(s2.top());
                    s2.pop();
                }
                s2.push(rep[i]);
            }
            else if (rep[i] == ')')
            {
                while ( true ) {
                    if (s2.top() == '(') {
                        s2.pop();
                        break;
                    } else {
                        s1.push(s2.top());
                        s2.pop();
                    }
                }
            }
            else
            {
                s2.push(rep[i]);
            }
        }
    }
    while ( !s2.empty() ) {
        s1.push(s2.top());
        s2.pop();
    }
    int index = 0;
    while ( !s1.empty() ) {
        rep[index++] = s1.top();
        s1.pop();
    }
    for (int i=index-1; i>=0; --i) printf("%c ", rep[i]);
    for (int i=index-1; i>=0; --i)
    {
        if (isalnum(rep[i]))
            s1.push(rep[i]);
        else
        {
            int b = s1.top() - '0';
            s1.pop();
            int a = s1.top() - '0';
            s1.pop();
            int ans =  cal(a, b, rep[i]);
            s1.push(ans+'0');
        }
    }
    printf("\nans = %d", s1.top()-'0');
}

int main()
{
    Init();
    puts("Input the expression:"); // 3*2^(4+2*2-1*3)-5
    scanf("%s", rep);
    Infixation(rep);

    return 0;
}
