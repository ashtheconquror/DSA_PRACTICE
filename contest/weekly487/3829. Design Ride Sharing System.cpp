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

class RideSharingSystem {
public:
    queue<int> riderQ;
    queue<int> driverQ;
    unordered_set<int>activeRiders;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        riderQ.push(riderId);
        activeRiders.insert(riderId);
    }
    
    void addDriver(int driverId) {
        driverQ.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        vector<int> ans;
        while(!riderQ.empty() && activeRiders.find(riderQ.front()) == 
             activeRiders.end())  {
            riderQ.pop();
             }
        if(riderQ.empty() || driverQ.empty()) {
            ans = {-1, -1};
            return ans;
        }
        int driver = driverQ.front();
        driverQ.pop();

        int rider = riderQ.front();
        riderQ.pop();

        activeRiders.erase(rider);

        ans = {driver, rider};
        return ans;
    }
    
    void cancelRider(int riderId) {
        activeRiders.erase(riderId);
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    return 0;
}