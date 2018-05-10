#include <cstdio>
#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
using namespace std;

bool have_pater[30];

int main()
{
    int n;
    string head, line;
    cin >> head;

    memset(have_pater,0,sizeof(have_pater));
    for (int i=0; i<head.length(); ++i)
        if (head[i] == ':')
            have_pater[head[i-1]-'a'] = 1;

    cin >> n;
    for (int k=1; k<=n; ++k)
    {
        getline(cin, line);
        bool deduce = 0;
        for (int i=0; i<line.length(); ++i) {
            if (line[i] == ' ') {
                deduce = 1;
                break;
            }
        }
        if ( !deduce ) {
            puts(line);
            continue;
        }

        stringstream ss.str(line);

        printf("Case %d: ", k);
    }
    return 0;
}
/*
albw:x
4
ls -a -l -a documents -b
ls
ls -w 10 -x -w 15
ls -a -b -c -d -e -l

Case 1: -a -l
Case 2:
Case 3: -w 15 -x
Case 4: -a -b
*/
