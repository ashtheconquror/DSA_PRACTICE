//3350. Adjacent Increasing Subarrays Detection II
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        int currRun = 1;
        int prevRun = 0;
        int maxRun = 0;

        for(int i = 1; i < n; i++) {
            if(nums[i-1] < nums[i]){
                currRun++;
            } else {
                maxRun = max(maxRun, currRun/2);
                currRun = 1;
            }

            maxRun = max(maxRun, currRun/2);
        }
        return maxRun;
    }
};