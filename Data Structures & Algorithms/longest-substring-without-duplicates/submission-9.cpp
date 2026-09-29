class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int res = 0;
        unordered_map<char, int> hash;

        for(int r = 0; r < (int)s.size(); r++) {
            if(hash.contains(s[r])) {
                l = max(l, hash[s[r]] + 1);
            } 
            hash[s[r]] = r;
            res = max(res, r - l + 1);
        }
        return res;
    }
};

/*
pwwkew

duplicate char found -> set l to max between l and the index of duplicate char we just found
*/