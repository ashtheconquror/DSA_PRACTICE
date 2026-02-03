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
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i+1 < n && nums[i] < nums[i+1]) {
            i++;
        }
        if(i == 0 || i == n - 1) {
            return false;
        }
        while(i+1 < n && nums[i] > nums[i+1]) {
            i++;
        }
        if(i == 0 || i == n-1) {
            return false;
        }
        while(i+1 < n && nums[i] < nums[i+1]) {
            i++;
        }
        if(i == n - 1) {
            return true;
        }
        return false;
    }
};
/*
2,2,-1,-2,4

-1, 2

*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    return 0;
}