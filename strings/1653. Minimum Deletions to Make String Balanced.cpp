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
//Approach - 1
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int cnt = 0;
        stack<char> st;
        for(int i = 0; i < n; i++) {
            if(!st.empty() && st.top() == 'b' && s[i] == 'a') {
                st.pop();
                cnt++;
            } else {
                st.push(s[i]);
            }
        }
        return cnt;
    }
};
//Approach - 2

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    return 0;
}