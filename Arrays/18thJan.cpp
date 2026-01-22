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
    int largestMagicSquare(vector<vector<int>>& grid) {
        int rows = grid.size
        int cols = grid[0].size();

        //Row wise prefix sum
        vector<vector<int>> rowCumSum(rows, vector<int>(cols));
        for(int i = 0; i < rows; i++) {
            rowCumSum[i][0] = grid[i][0];
            for(int j = 1; j < cols; j++) {
                rowCumSum[i][j] = rowCumSum[i][j-1] + grid[i][j];
            }
        }

        //Column wise prefix sum
        vector<vector<int>> colCumSum(rows, vector<int>(cols));
        for(int j = 0; j < cols; j++) {
            colCumSum[0][j] = grid[0][j];
            for(int i = 1; i < rows; i++) {
                colCumSum[i][j] = colCumSum[i-1][j] + grid[i][j];
            }
        }

        //Try all possible

        for(int side = min(rows,cols); side >= 2; side--) {
            for(int i = 0; i+side - 1 < rows; i++) {
                for(int j = 0; j +side -1 < cols; j++) {
                    int targetSum = rowCumSum[i][j+side-1] - (j > 0 ? rowCumSum[i][j-1] : 0);
                    bool allSame = true;
                    //check rows
                    for(int r = i+1; r < i + side; r++) {
                    int rowSum = rowCumSum[r][j+side-1] - (j > 0 ? rowCumSum[r][j-1] : 0);
                    if(rowSum != targetSum) {
                        allSame = false;
                        break;
                    }
                    }   
                    if(!allSame)
                        continue;
                    
                    for(int c = j; c < j + side; c++) {
                        int colSum = colCumSum[i+side - 1][c] - (i > 0 ? colCumSum[i-1][c] : 0);
                        if(colSum != targetSum) {
                            allSame = false;
                            break;
                        }
                    }
                    if(!allSame)
                        continue;
                    int diag = 0;
                    int adiag = 0;
                    for(int k = 0; k < side; k++) {
                         diag+= grid[i+k][j+k];
                         adiag += grid[i+k][j+side-1-k];
                    }
                    if(diag == targetSum && adiag == targetSum) {
                        return side;
                    }
                }
            }
        }
        return 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    return 0;
}