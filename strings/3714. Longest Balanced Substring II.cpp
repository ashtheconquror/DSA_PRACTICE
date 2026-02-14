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
    int helper(string& s, int ch1, int ch2) {
        int n = s.length();
        int MaxLength = 0;
        unordered_map<int, int> diffMap;
        int count1 = 0, count2 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != ch1 && s[i] != ch2) {
                diffMap.clear();
                count1 = 0;
                count2 = 0;
                continue;
            }

            if (s[i] == ch1)
                count1++;
            if (s[i] == ch2)
                count2++;
            if (count1 == count2) {
                MaxLength = max(MaxLength, count1 + count2);
            }
            int diff = count1 - count2;
            if (diffMap.count(diff)) {
                MaxLength = max(MaxLength, i - diffMap[diff]);
            } else {
                diffMap[diff] = i;
            }
        }
        return MaxLength;
    }
    int longestBalanced(string s) {
        int n = s.length();
        int MaxLength = 0;
        // case 1 = 'aaaaa'
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                MaxLength = max(MaxLength, count);
                count = 1;
            }
        }
        MaxLength = max(MaxLength, count);
        // case 2
        MaxLength = max(MaxLength, helper(s, 'a', 'b'));
        MaxLength = max(MaxLength, helper(s, 'a', 'c'));
        MaxLength = max(MaxLength, helper(s, 'b', 'c'));

        // case 3
        int countA = 0;
        int countB = 0;
        int countC = 0;

        unordered_map<string, int> diffMap;
        for (int i = 0; i < n; i++) {

            if (s[i] == 'a')
                countA++;
            else if (s[i] == 'b')
                countB++;
            else
                countC++;

            if (countA == countB && countB == countC) {
                MaxLength = max(MaxLength, countA + countB + countC);
            }
            int diffAB = countA - countB;
            int diffAC = countA - countC;
            string key = to_string(diffAB) + '_' + to_string(diffAC);

            if (diffMap.count(key)) {
                MaxLength = max(MaxLength, i - diffMap[key]);
            } else {
                diffMap[key] = i;
            }
        }
        return MaxLength;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    return 0;
}