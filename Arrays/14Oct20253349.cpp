#include <bits/stdc++.h>
using namespace std;
#define int long long

// Problem Statement
/*

*/

// Small Observations
/*

*/

void solve() {
  
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}class Solution {
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