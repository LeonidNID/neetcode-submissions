class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::set<char> mp; // window state (only unique elements)!
        int l = 0; // left
        int res = 0; // result

        for(int r = 0; r < s.size(); r++) { // r loop
            while(mp.contains(s[r])) { // while violates
                mp.erase(s[l]); // update window state
                l++; // shrink from left
            }
            mp.insert(s[r]); // update window to include arr[r]
            res = max(res, r - l + 1); // only unique elements
        }
        return res;
    }
};

/*
a b c a b c b b
      |     |

duplicate char found -> set l to max between l and the index of duplicate char we just found
*/