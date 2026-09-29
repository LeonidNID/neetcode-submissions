class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> symbols;
        int left = 0;
        int ret = 0;

        for(int r = 0; r < s.size(); r++) {
            while(symbols.contains(s[r])) {
                symbols.erase(s[left]);
                left++;
            }
            symbols.insert(s[r]);
            ret = max(ret, r - left + 1);
        }
        return ret;
    }
};

/*
contiguous sequence of character

zxyzxyz

// Idea: Expand sliding window through string s
Hashset to track occurences, one iteger res. Update along. 

if hashset contains read element -> res = max(res, curlen), clear hashset
*/