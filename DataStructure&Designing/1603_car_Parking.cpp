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

class ParkingSystem {
public:
    int b, m, s;
    ParkingSystem(int big, int medium, int small) {
        b = big;
        m = medium; 
        s = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1 && b == 0 
        || carType == 2 && m == 0 
        || carType == 3 && s == 0) {
            return false;
        }
        if(carType == 1) b--;
        else if(carType == 2) m--;
        else s--;

        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}