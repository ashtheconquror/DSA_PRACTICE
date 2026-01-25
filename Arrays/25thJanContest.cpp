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
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        while(i > 0 && nums[i] - nums[i-1] >= 1) {
            i--;
        }

        return i;
    }
}; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    return 0;
}