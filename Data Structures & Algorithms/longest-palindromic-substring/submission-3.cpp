class Solution {
public:
    string longestPalindrome(string s) {
        int resIdx = 0;
        int resLen = 0;

        /*
        Idea: Check each position in the string.
        Palindromes grow from the INSIDE (Midpoint) out.
        */
        for(int i = 0; i < s.size(); i++) {
            // Even length
            int l = i;
            int r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                if(r - l + 1 > resLen) {
                    resLen = r - l + 1;
                    resIdx = l; // Start palindrome at l
                }
                l--;
                r++;
            }

            // Odd length
            l = i;
            r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                if(r - l + 1 > resLen) {
                    resLen = r - l + 1;
                    resIdx = l; // Start palindrome at l
                }
                l--;
                r++;
            }
        }
        return s.substr(resIdx, resLen);
    }
};