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
class Solution {
public:
//time complexity = O(n) .. but space complexity = O(2n)
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> left_b(n, 0);
        vector<int> right_a(n, 0);

        int leftcntb = 0;
        for (int i = 0; i < n; i++) {
            left_b[i] = leftcntb;
            if (s[i] == 'b')
                leftcntb++;
        }

        int rightcnta = 0;
        for (int i = n - 1; i >= 0; i--) {
            right_a[i] = rightcnta;
            if (s[i] == 'a') {
                rightcnta++;
            }
        }
        int cnt = INT_MAX;

        for (int i = 0; i < n; i++) {
            cnt = min(cnt, left_b[i] + right_a[i]);
        }
        return cnt;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    return 0;
}