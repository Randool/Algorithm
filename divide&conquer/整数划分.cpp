#include <iostream>
using namespace std;

// ���ֳɲ�ͬ������֮����ʽ
// n : ����
// m : ��������
int partition(int n, int m) {
    if ( (n == 1) || (m == 1) )
        return 1;
    if ( n <= m )
        return partition(n, n-1) + 1;
    return partition(n, m-1) + partition(n-m, m);
}

int main() {
    cout << partition(20, 20);
    return 0;
}
