#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

#define show(x) printf("%d", x)
#define shown(x) printf("%d\n", x)

int depose(int n, const vector<int> &vec) {
    int result= 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < n; ++i) pq.push(0);
    for (int i = 0; i < vec.size(); ++i) {
        int _min = pq.top();
        //shown(_min);
        result += _min;
        pq.pop();
        pq.push(_min + vec[i]);
    }
    return result;
}


int main() {
    FILE *fi = fopen("input.txt", "r");
    FILE *fo = fopen("output.txt", "w");

    int n, s, t;
    vector<int> vt;

    fscanf(fi, "%d %d", &n, &s);
    for (int i = 0; i < n; ++i) {
        fscanf(fi, "%d", &t);
        vt.push_back(t);
    }
    sort(vt.begin(), vt.end(), less<int>());

    int result = depose(s, vt) / n;
    printf("%d", result);
    fprintf(fo, "%d", result);

    return 0;
}
