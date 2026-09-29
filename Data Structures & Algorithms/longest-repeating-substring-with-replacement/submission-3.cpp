class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp; // window state
        int l = 0; // left
        int res = 0; // res
        int maxFreq = 0;

        for(int r = 0; r < s.size(); r++) { 
            mp[s[r]]++; // update window to include arr[r]
            maxFreq = max(maxFreq, mp[s[r]]);
            
            while((r - l + 1) - maxFreq > k && l < r) {
                mp[s[l]]--; // shrink window
                l++; // move left fwd
            }
            res = max(res, r - l + 1); // update res
        }
        return res;
    }
};


/*
check condition including window size and k each iteration. resize window one by one via while loop

What is the violation condition?
-> non mostfreq. char showing up > k times
-> (r - l + 1) - s[maxChar] > k
   (wndowSize)

AAABABB, k=1
total len: 6:

A -> s[A] -> res = 1
A -> s[A] -> res = 2
A -> s[A] -> res = 3
B -> s[B] -> potential res : 4 

*/