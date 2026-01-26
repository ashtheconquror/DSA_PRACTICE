#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *n): val(x), next(n) {}
};

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        int n = nums.size();
        int minDiff = INT_MAX;
        sort(begin(nums), end(nums));
        for(int i = 0; i < n-1; i++) {
            minDiff = min(minDiff, abs(nums[i] - nums[i+1]));
        }
        vector<vector<int>>  ans;

        for(int i = 0; i < n-1; i++) {
          
                if(abs(nums[i] - nums[i+1]) == minDiff) {
                    ans.push_back({nums[i], nums[i+1]});
                }
            
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    return 0;
}