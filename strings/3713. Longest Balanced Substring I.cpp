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
    bool checkBalanced(vector<int>& freq) {
        int common = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0) continue;
            if(common == 0) {
                common = freq[i];
            } else if(freq[i] != common) {
                return false;
            }

        }
        return true;
    }
    int longestBalanced(string s) {
        int n = s.size();
        int res = 0;

        for(int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for(int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                if(checkBalanced(freq)) {
                    res = max(res, j - i + 1);
                }
            }
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    return 0;
}