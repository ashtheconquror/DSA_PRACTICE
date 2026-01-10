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
    /*
    & -> why we do this well when we pass the variables in this problem it s1 and s2
    by doing &s1 and &s2 we are passing them by reference which avoids making extra 
    copy of s1 and s2 and saving time required to make the this extra copies
    */

    //T.C = (n * M)
    int n, m;
    int dp[10001][1001];
    int solve(string &s1, string &s2, int i, int j) {
        if(i >= n && j >= m){ // Dono bhi exhaust ho gaye nothing is same so no deletion
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(i >= n) {
            return dp[i][j] = s2[j] + solve(s1, s2, i, j+1);
        } else if(j >= m) {
            return dp[i][j] = s1[i] + solve(s1, s2, i+1, j);
        }

        if(s1[i] == s2[j]) {
            return dp[i][j] = solve(s1, s2, i+1, j+1);
        }
        //Two possiblities

        int delete_s1_i = s1[i] + solve(s1, s2, i+1, j);

        int delete_s2_j = s2[j] + solve(s1, s2, i, j+1);

        return dp[i][j] = min(delete_s1_i, delete_s2_j);

    }
    int minimumDeleteSum(string s1, string s2) {
        n = s1.size();
        m = s2.size();
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, 0, 0);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    return 0;
}