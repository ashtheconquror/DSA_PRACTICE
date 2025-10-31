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
    bool checkAllbitSet(int x) {
        return (x & (x + 1)) == 0;
    }
    int smallestNumber(int n) {
        //first approach raw
        int result = n;
        if(!checkAllbitSet(n)) {
            result++;
        }
        return result;
    }
};

//second approach
class Solution {
public:
    int smallestNumber(int n) {
        //first approach raw
        int result = 1;
        while(result < n) {
            result = result * 2 + 1;
        }
        return result;
    }
};

//Third Approach

class Solution {
public:
    int smallestNumber(int n) {
        int bits = log2(n) + 1;
        return (1 << bits) - 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    return 0;
}