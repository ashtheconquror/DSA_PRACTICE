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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& vec) {
        if(root == NULL) {
            return;
        }

        inOrder(root->left, vec);
        vec.push_back(root->val);
        inOrder(root->right, vec);
    }
    TreeNode* construct(vector<int>& vec, int l, int r) {
        if(l > r) {
            return NULL;
        }
        int mid = l + (r - l)/2;
        TreeNode* root = new TreeNode(vec[mid]);
        root->left = construct(vec, l, mid - 1);
        root->right = construct(vec, mid + 1, r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vec;
        inOrder(root, vec);
        int l  = 0;
        int r = vec.size() - 1;
        return construct(vec, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    return 0;
}