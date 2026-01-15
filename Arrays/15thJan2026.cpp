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
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(begin(hBars), end(hBars));
        sort(begin(vBars), end(vBars));

        int maxConsecutivehBars = 1;
        int maxConsecutivevBars = 1;
        int currConsecutivehBars = 1;
        for(int i = 1; i < hBars.size(); i++) {
            if(hBars[i] -  hBars[i - 1] == 1) {
                currConsecutivehBars++;
            } else {
                currConsecutivehBars = 1;
            }
            maxConsecutivehBars = max(maxConsecutivehBars, currConsecutivehBars);
        }
        int currConsecutivevBars = 1;
        for(int i = 1; i < vBars.size(); i++) {
            if(vBars[i] -  vBars[i - 1] == 1) {
                currConsecutivevBars++;
            } else {
                currConsecutivevBars = 1;
            }
            maxConsecutivevBars = max(maxConsecutivevBars, currConsecutivevBars);
        }

        int side = min(maxConsecutivevBars,maxConsecutivehBars) + 1;
        return side * side;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    return 0;
}