class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // map for char -> index of char in s
        unordered_map<char, int> symbols;
        int res = 0;
        int l = 0;

        for(int r = 0; r < s.size(); r++) {
            // if s[r] is already in map
            if(symbols.find(s[r]) != symbols.end()) {
                // set l to max between index of s[r] in map (+1) and l
                l = max(symbols[s[r]] + 1, l);
            }
            // set the index of s at index r to r
            symbols[s[r]] = r;
            // res is the max of current res vs current window len
            res = max(res, r - l + 1);
        }
        return res;
    }
};