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
    typedef pair<ll,ll> P;
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        set<P> kMinimum;
        set<P> remaining;
        ll sum = 0;
        int i = 1;
        while(i - dist < 1) {
            kMinimum.insert({nums[i], i});
            sum += nums[i];
            if(kMinimum.size() > k - 1) {
                P temp = *kMinimum.rbegin();
                sum -=  temp.first;
                remaining.insert(temp);
                kMinimum.erase(temp);
            }
            i++;
        }
        ll result = LONG_MAX;
        while (i < n) {
            kMinimum.insert({nums[i], i});
            sum += nums[i];
            if(kMinimum.size() > k - 1) {
                P temp = *kMinimum.rbegin();
                sum -=  temp.first;
                remaining.insert(temp);
                kMinimum.erase(temp);
            }
            result = min(result, sum);
            P remove = {nums[i - dist], i - dist};
            if(kMinimum.count(remove)) {
                kMinimum.erase(remove);
                sum -= remove.first;
                if(!remaining.empty()) {
                    P temp = *remaining.begin();
                    kMinimum.insert(temp);
                    sum += temp.first;
                    remaining.erase(temp);
                }
            }else {
                remaining.erase(remove);
            }
            i++;
        }
        return nums[0] + result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    return 0;
}