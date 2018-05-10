// https://vjudge.net/problem/HYSBZ-3229
#include <cstdio>
#include <vector>
#include <iostream>
#define MAX 0x7fffff
using namespace std;

long long GarsiaWachs(vector<int> &A) {
	long long result = 0;
    A.insert(A.begin(), MAX);
    A.push_back(MAX);
    while (A.size() > 3)
    {
        int i = 1, j, temp;
        while (A[i] >= A[i+2]) ++i;
        temp = A[i] + A[i+1];
        result += (long long)temp;
        A.erase(A.begin()+i, A.begin()+i+2);

        j = i-1;
        while (A[j] < temp) --j;
        A.insert(A.begin()+j+1, temp);
    }
    return result;
}

int main() {
    int n, t;
	while(cin >> n) {
	    vector<int> A;
		for (int i=1; i<=n; ++i) {
            scanf("%d", &t);
            A.push_back(t);
		}
        cout << GarsiaWachs(A) << endl;
	}
	return 0;
}
