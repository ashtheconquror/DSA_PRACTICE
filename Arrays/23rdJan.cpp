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
    typedef long long ll;
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();

        vector<ll> temp(n);
        for(int i = 0; i < n; i++) {
            temp[i] = nums[i];
        }
        set<pair<ll, int>> st;

        vector<int> nexIdx(n);
        vector<int> prevIdx(n);
        for(int i = 0; i < n; i++) {
            nexIdx[i] = i+1;
            prevIdx[i] = i-1;
        }

        int badpairs = 0;
        for(int i = 0; i < n - 1; i++) {
            if(temp[i] > temp[i+1]) {
                badpairs++;
            }
            st.insert({temp[i] + temp[i+1], i});
        }
        int operations = 0;

        while(badpairs > 0) {
            int first = st.begin()->second;
            int second = nexIdx[first];

            int first_left = prevIdx[first];
            int second_right = nexIdx[second];

            st.erase(begin(st));
            if(temp[first] > temp[second]) {
                badpairs--;
            }
            //(d, {a, b})
            if(first_left >=  0) {
                if(temp[first_left] > temp[first] 
                && temp[first_left] <= temp[first] + temp[second]) {
                    badpairs--;
                }
                else if(temp[first_left] <= temp[first]
                && temp[first_left] > temp[first] + temp[second]) {
                    badpairs++;
                }
            }
            if(second_right < n) {
                if(temp[second_right] >= temp[second]
                && temp[second_right] < temp[first] + temp[second]) {
                    badpairs++;
                } else if(temp[second_right] < temp[second]
                && temp[second_right] >= temp[first] + temp[second]) {
                    badpairs--;
                }
            }
            if(first_left >= 0) {
                st.erase({temp[first_left] + temp[first], first_left});
                st.insert({temp[first_left] + temp[first] + temp[second], first_left});
            }
            if(second_right < n) {
                st.erase({temp[second] + temp[second_right], second});
                st.insert({temp[first] + temp[second] + temp[second_right], first});
                prevIdx[second_right] = first;
            }
            nexIdx[first] = second_right;
            temp[first] += temp[second];
            operations++;
        }
        return operations;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    return 0;
}