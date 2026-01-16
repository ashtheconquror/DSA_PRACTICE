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
    const int M = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);

        vFences.push_back(1);
        vFences.push_back(n);

        unordered_set<int>widths;
        unordered_set<int> heights;

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        for(int i = 0; i < vFences.size(); i++) {
            for(int j = i+1; j < vFences.size(); j++) {
                int width = vFences[j] - vFences[i];
                widths.insert(width);
            }
        }
        int maxSide = 0;
        for(int i = 0; i < hFences.size(); i++) {
            for(int j = i+1; j < hFences.size(); j++) {
                int height = hFences[j] - hFences[i];
                if(widths.find(height) != widths.end()) {
                    maxSide = max(maxSide, height);
                }
            }
        }

        return maxSide == 0 ? -1 : (1LL * maxSide * maxSide) % M;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    return 0;
}