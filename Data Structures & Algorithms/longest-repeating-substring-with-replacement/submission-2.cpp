class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> symbols;
        int res = 0;
        int maxFreq = 0;
        int l = 0;

        for(int r = 0; r < s.size(); r++) {
            symbols[s[r]]++;
            maxFreq = max(maxFreq, symbols[s[r]]);

            while((r - l + 1) - maxFreq > k) {
                symbols[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};


/*

AAABABB, k=1
total len: 6:

A -> s[A] -> res = 1
A -> s[A] -> res = 2
A -> s[A] -> res = 3
B -> s[B] -> potential res : 4 

*/