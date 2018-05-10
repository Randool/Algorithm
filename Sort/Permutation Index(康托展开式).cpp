//Permutation Index
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    long long fac(int n) {
        long long ans = 1;
        while (n) ans *= (n--);
        return ans;
    }
public:
    long long permutationIndex(vector<int>& A) {
        // 无重复数字
        long long ans = 0, position = A.size() - 1;
        for (int i=0; i<A.size(); ++i)
        {
            long long cnt_min = 0;
            for (int j=i+1; j<A.size(); ++j)
                if (A[j] < A[i])
                    ++cnt_min;
            ans += (cnt_min * fac(position--));
        }
        return ans + 1;
    }

    long long permutationIndexII(vector<int>& A) {
    	// 有重复数字
        long long ans = 0;
		long long position = A.size() - 1;

        if (A.empty())
			return ans;

        map<int, int> mii;
        vector<int> nums;
        for (int i=0; i<A.size(); ++i) {
            if (mii[A[i]]) {
                mii[A[i]] += 1;
            }
            else {
                mii[A[i]] = 1;
                nums.push_back(A[i]);
            }
        }
        for (int i=0; i<A.size(); ++i)
        {
            long long cnt_min = 0;
            for (int j=i+1; j<A.size(); ++j)
            {
                if (A[j] < A[i])
                    ++cnt_min;
            }
            //printf("%lld * %lld ", fac(position), cnt_min);
            long long tmp = fac(position--) * cnt_min;
            
			for (int k=0; k<nums.size(); ++k) {
            	//printf("/ %lld ", fac(mii[nums[k]]));
                tmp /= fac(mii[nums[k]]);
			}
			//printf(" = %lld\n", tmp);
			mii[A[i]] -= 1;
            ans += tmp;
        }
        return ans + 1;
    }
};

int main()
{
    int tmp[] = {10,10,10,10,9,8,7,6,5,4,3,2,1};
    vector<int> A(tmp, tmp+13);
    Solution sol;
    cout << sol.permutationIndexII(A);

    return 0;
}
