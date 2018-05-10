#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int swap_times = 0;
    int fa(int index) { return (index-1)/2; }
    int lt(int index) { return index<<1+1; }
    int rt(int index) { return index<<1+2; }
public:
    void heapify(vector<int> &A, int len) {
        for (int i=1; i<len; ++i) {
            int index = i;
            while (index && A[fa(index)] < A[index]) {
                ++swap_times;
                swap(A[fa(index)], A[index]);
                index = fa(index);
            }
        }
    }
    /**
     * 1. 交换首尾
     * 2. 尾出列
     * 3. 重新建立堆
     */
    void heapSort(vector<int> &A) {
        heapify(A, A.size());
        for (int i=A.size()-1; i>=0; --i) {
            swap(A[i], A[0]);
            heapify(A, i);
        }
        cout << "Total swap times : " << swap_times << endl;
    }
};

int get_random(int a, int len) {
    int result = rand() % len + a;
    return result;
}

int main()
{
    srand((unsigned)time(0));
    int times; cin >> times;
    vector<int> A;
    for (int i = 0; i < times; ++i)
        A.push_back(get_random(1, 200));

    Solution sol;
    sol.heapify(A, A.size());
    cout << "Raw array : ";
    for (int i=0; i<A.size() ;++i)
        cout << A[i] << " ";
    cout << endl << endl;

    sol.heapSort(A);
    cout << "Sorted array : ";
    for (int i=0; i<A.size() ;++i)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
