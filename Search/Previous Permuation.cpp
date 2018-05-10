#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums)
    {
        // write your code here
    }
};

int main()
{
    int num[] = {1,3,2,3};
    vector<int> nums(num, num+4);
    Solution sol;
    vector<int> result = sol.previousPermuation(nums);

    for (int i=0; i<result.size(); ++i)
        cout << result[i] << " ";

    return 0;
}
