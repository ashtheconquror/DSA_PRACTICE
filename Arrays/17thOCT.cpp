/*
3003. Maximize the Number of Partitions After Operations
-> (hard)
*/



#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<long long, int> mp;

    string S;
    int K;

    int solve(long long i, long long uniqueChars, bool Canchange) {
        long long key = ((i << 27) | (uniqueChars << 1) | Canchange);
        if(mp.find(key) != mp.end()) {
            return mp[key];
        }
        if (i >= S.length()) {
            return 0;
        }

        int charIndex = S[i] - 'a';
        int newuniqueChar = uniqueChars | (1 << charIndex);
        int uniquecharcnt = __builtin_popcount(newuniqueChar);

        int res = 0;
        if (uniquecharcnt > K) {
            res = 1 + solve(i + 1, 1 << charIndex, Canchange);
        } else {
            res = solve(i + 1, newuniqueChar, Canchange);
        }

        if (Canchange == true) {
            for (int n = 0; n < 26; n++) {
                int newCharset = uniqueChars | (1 << n);
                int newUniquecharcnt = __builtin_popcount(newCharset);
                if (newUniquecharcnt > K) {
                    res = max(res, 1 + solve(i + 1, 1 << n, false));
                } else {
                    res = max(res ,solve(i + 1, newCharset, false));
                }
            }
        }
        return mp[key] = res;
    }
    int maxPartitionsAfterOperations(string s, int k) {
        S = s;
        K = k;
        return solve(0, 0, true)+1;
    }
};

int main() {
        
}