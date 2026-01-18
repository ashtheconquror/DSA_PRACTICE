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
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        int maxSide = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int bottomleftX = max(bottomLeft[i][0], bottomLeft[j][0]);
                int bottomLeftY = max(bottomLeft[i][1], bottomLeft[j][1]);



                int topRightX = min(topRight[i][0], topRight[j][0]);
                int topRightY = min(topRight[i][1], topRight[j][1]);

                //width
                int width = topRightX - bottomleftX;

                int height = topRightY - bottomLeftY;

                int side = min(width, height);

                maxSide = max(side, maxSide);

            }
        }
        return 1LL * maxSide * maxSide;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    return 0;
}