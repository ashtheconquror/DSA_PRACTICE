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
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long result = 0;
        int n = nums.size();
        vector<int> diff(n);

        for(int i = 0; i < n; i++) {
            diff[i] = target[i] - nums[i];
        }
        int curr = 0, prev = 0;
        for(int i = 0; i < n; i++) {
            curr = diff[i];
            //case1:
            if((curr > 0 && prev < 0) || (curr < 0 && prev > 0)) {
                result += abs(curr);
            }
            else if(abs(curr) > abs(prev)) {
                result += abs(curr - prev);
            }
            curr = prev;
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    return 0;
}