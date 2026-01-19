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
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> prefix(rows, vector<int>(cols, 0));


        for(int i = 0 ; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                prefix[i][j] = (i > 0 ? prefix[i-1][j] : 0) 
                            + (i > 0 ? prefix[i][j-1] : 0)
                            - (i > 0 && j > 0 ? prefix[i-1][j-1]: 0)
                            + mat[i][j];
            }
        }

        auto sumSquare = [&](int i, int j , int r2, int c2) {
            int sum = prefix[r2][c2];
            if(i > 0)
                sum -= prefix[i-1][c2];
            if(j > 0)
                sum -= prefix[r2][j-1];
            if(i > 0 && j > 0)
                sum += prefix[i-1][j-1];

            return sum;
        };
        int best = 0;
        for(int i = 0;i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                for(int k = 0; k < min(rows - i, cols - j); k++) {
                    //offset for loop
                    int r2 = i + k;
                    int c2 = j + k;
                    int sum = sumSquare(i, j, r2, c2);
                    if(sum <= threshold) {
                        best = max(best, k + 1);
                    } else {
                        break;
                    }
                }
            }
        }
        return best;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    return 0;
}