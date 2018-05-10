#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main() {
    FILE *fi = fopen("input.txt", "r");
    FILE *fo = fopen("output.txt", "w");

    int n, t, a, b;
    priority_queue<int, vector<int>, greater<int> > _pq;
    priority_queue<int, vector<int>, less<int> >    pq_;

    fscanf(fi, "%d", &n);
    for (int i = 0; i < n; ++i) {
        fscanf(fi, "%d", &t);
        _pq.push(t);
        pq_.push(t);
    }

    int _cnt = 0, cnt_ = 0, sum;

    while (_pq.size() != 1) {
        a = _pq.top(), _pq.pop();
        b = _pq.top(), _pq.pop();
        sum = a + b - 1;
        _cnt += sum;
        _pq.push(sum+1);
    }

    while (pq_.size() != 1) {
        a = pq_.top(), pq_.pop();
        b = pq_.top(), pq_.pop();
        sum = a + b - 1;
        cnt_ += sum;
        pq_.push(sum+1);
    }

    printf("%d %d", cnt_, _cnt);
    fprintf(fo, "%d %d", cnt_, _cnt);

    return 0;
}
