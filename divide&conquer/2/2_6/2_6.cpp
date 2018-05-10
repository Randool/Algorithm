#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * ��׳˵ĺ���
 */
int factorial(int n) {
    if (!n) return 1;
    int result = n;
    while (--n) result *= n;
    return result;
}

/**
 * ��������е��ֵ���
 */
int get_ranking(const vector<int> &nums) {
    int result = 0, size = nums.size();
    for (int i = 0; i < size; ++i) {
        int _min = 0;
        for (int j = i + 1; j < size; ++j) {
            if (nums[j] < nums[i]) ++_min;
        }
        result += _min * factorial(size-i-1);
    }
    return result;
}

/**
 * ����һ�����е��㷨
 */
bool next(vector<int> &nums) {
    int p = nums.size()-2;
    while (p >= 0 && nums[p] >= nums[p+1]) --p;
    if (p == -1) return false;

    int q = nums.size()-1;
    while (nums[q] <= nums[p]) --q;
    swap(nums[p], nums[q]);
    reverse(nums.begin()+p+1, nums.end());
    return true;
}

/**
 * ��ӡ������е�Ԫ��
 */
void show(const vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i)
        cout << nums[i] << " ";
    cout << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, t;
    cin >> n;
    vector<int> nums;
    while (n--) {
        cin >> t;
        nums.push_back(t);
    }
    //show(nums);
    cout << get_ranking(nums) << endl;
    if (next(nums)) {
        show(nums);
    }

    return 0;
}
