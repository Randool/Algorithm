#include <string>
#include <iostream>
#include <algorithm>
#define MAXN 5005
using namespace std;

int main()
{
    string bit;
    while (cin >> bit)
    {
        sort(bit.begin(), bit.end());
        cout << bit << endl;
        while( next_permutation(bit.begin(), bit.end()) )
        {
            cout << bit << endl;
        }
    }
	return 0;
 }
