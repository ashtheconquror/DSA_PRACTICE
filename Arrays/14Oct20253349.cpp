#include <bits/stdc++.h>
using namespace std;
#define int long long
class Solution {
public:

//Unoptimized apporach
    bool isIncreasing(vector<int>& nums, int q, int w) 
    {
        for(int i = q+1; i <= w; i++)
        {
            if(nums[i-1] >= nums[i])
            {
                return false;
            }
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        bool first = 0;
        bool second = 0;
        for(int startIndex = 0; startIndex+2*k <= n; startIndex++) 
        {
            first = isIncreasing(nums,  startIndex,  startIndex + k - 1);
            second = isIncreasing(nums,  startIndex+k,  startIndex+ k + k - 1);

            if(first && second) {
                return true;
            }
        }
        if(first && second) {
            return true;
        }

        return false;

        }
};
int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int k = 3;
    cout << (s.hasIncreasingSubarrays(nums, k) ? "true" : "false") << endl; 
}