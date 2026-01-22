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
    int minPairSum(vector<int>& nums){
        int minSum = INT_MAX;
        int index = -1;
        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i] + nums[i+1] < minSum) {
                index = i;
                minSum = nums[i] + nums[i+1];
            }
        }
        return index;
    }
    int minimumPairRemoval(vector<int>& nums) {
       
       int ops = 0;
       while(!is_sorted(begin(nums), end(nums))) {
            int index = minPairSum(nums);
            nums[index] = nums[index] + nums[index+1];

            nums.erase(begin(nums) + index + 1);
            ops++;
       }
       return ops;

    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    return 0;
}