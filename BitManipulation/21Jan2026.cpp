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
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> result;
        for(int i = 0;i < n; i++) 
        {
            if(nums[i] == 2) {
                result.push_back(-1);
                continue;
            }
            bool found = false;
            for(int j = 1; j <= 32; j++) {
                if((nums[i] & (1 << j)) > 0) {
                    continue;
                }
                int prev = j - 1;

                //make the prev bit 0
                int x = (nums[i] ^ (1 << (j-1)));
                result.push_back(x);
                found = true;
                break;
            }
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