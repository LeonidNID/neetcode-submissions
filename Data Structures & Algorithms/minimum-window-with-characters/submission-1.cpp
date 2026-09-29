class Solution {
public:
    // O(n + k) with k number of unique chars.
    string minWindow(string s, string t) {
        if(s.size() < t.size() || t.empty()) return "";
        int resLen = INT_MAX;
        pair<int, int> res = {-1, -1};

        unordered_map<char, int> mp;
        for(char c : t) {mp[c]++;}

        unordered_map<char, int> window;
        int have = 0;
        int need = mp.size();

        int l = 0;
        for(int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;
            
            if(mp.count(c) && window[c] == mp[c]) {
                have++;
            }

            // violation condition: we have all characters but window is not smallest
            while(have == need) {
                if((r - l + 1) < resLen) {
                    resLen = r - l + 1;
                    res = {l, r};
                }
                window[s[l]]--;
                if(mp.contains(s[l]) && window[s[l]] < mp[s[l]]) { // key condition
                    have--;
                }
                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};

/*
Strings s and t, t shorter than s
Find shortest substring in s so that all letters of t are contained
n <= 1e5 => O(n) ideal

Idea:
Dynamic sliding window from the left.
if we don't have all T letters, keep expanding.
If we have all, first save that string
If all are contained, and we get a new one in the orig target, check if it is better to take in new one from the right and cut the left

Example:
OUZODYXAZV
  |   |     => ZODYX

OUZODYXAZV
     |  |   => YXAZ

Need:
- check if s[r]
*/