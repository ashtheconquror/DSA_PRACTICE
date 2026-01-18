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

    bool check (vector<vector<int>>& squares, double mid_y, double total_area) {
        double bottom_area = 0;
        for(auto &square: squares) {
            double y = square[1];
            double l = square[2];

            double boty = y;
            double topy = y + l;
            if(mid_y >= topy) {
                bottom_area += l * l;
            } else if(mid_y > boty) {
                bottom_area += (mid_y - boty) * l;
            }
        }
        return bottom_area >= total_area/2.0;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double low = INT_MIN;
        double high = INT_MAX;
        double total_area = 0.00000;

        for(auto &square: squares) {
            double x = square[0];
            double y = square[1];
            double l = square[2];
            total_area += l*l;
            

            low = min(low, y);
            high = max(high, y + l);

           
        }

        double result_y = 0.00000;

        while(high - low > 1e-5) {
            double mid_y = low + (high - low)/2;
            result_y = mid_y;

            if(check(squares, mid_y, total_area) == true) {
                high = mid_y;
            } else {
                low = mid_y;
            }
        }
        return result_y;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    return 0;
}