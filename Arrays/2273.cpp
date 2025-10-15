// Problem: Remove Anagrams
// Link: https://leetcode.com/problems/remove-anagrams/
// Date: 13 Oct 2025
// Approach: Sort each word and compare with previous
// Time Complexity: O(n * m log m) where n = number of words, m = average length of word

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s1, string s2) 
    {
        if(s1.size() != s2.size())
            return false;
        
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        return s1 == s2;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        
        result.push_back(words[0]);

        for(int i = 1; i < words.size(); i++)  
        {
            if(!isAnagram(words[i], words[i-1])) 
            {
                result.push_back(words[i]);
            }
           
            
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"abba","baba","bbaa","cd","cd"};
    vector<string> ans = sol.removeAnagrams(words);

    cout << "Result: ";
    for (auto &s : ans) cout << s << " ";
    cout << endl;
    return 0;
}