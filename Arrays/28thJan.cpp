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
    void floyd_Warshall(vector<vector<long long>> &adj_mat,vector<char>& original,vector<char>& changed, vector<int>& cost) {
        for(int i = 0; i < original.size(); i++) {
            int source      = original[i] - 'a';
            int destination = changed[i] - 'a';

            adj_mat[source][destination] = min(adj_mat[source][destination], (long long)cost[i]);
        }

            for(int k = 0; k < 26; k++) {
                for(int i = 0; i < 26; i++) {
                    for(int j = 0; j < 26; j++) {
                        adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k] + adj_mat[k][j]);
                    }
                }
            }   
        
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> adj_mat(26, vector<long long>(26, INT_MAX));

        floyd_Warshall(adj_mat, original, changed, cost);
        long long ans = 0;
        for(int i = 0; i < source.length(); i++) {
            if(source[i] == target[i]) {
                continue;
            }

            if(adj_mat[source[i] - 'a'][target[i] - 'a'] == INT_MAX) {
                return -1;
            }
            ans += adj_mat[source[i] - 'a'][target[i] - 'a'];
        }
        return ans;

    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    return 0;
}