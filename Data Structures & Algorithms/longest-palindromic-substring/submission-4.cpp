class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int resLen = 0;
        int resIdx = 0;

        for(int i = 0; i < n; i++) { // For all start positions
            // Odd size
            int l = i;
            int r = i;

            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r - l + 1 > resLen) {
                    resIdx = l;
                    resLen = r - l + 1;
                }
                l--;
                r++;
            } 

            // Even size
            l = i;
            r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r - l + 1 > resLen) {
                    resIdx = l;
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }
            
        }

        return s.substr(resIdx, resLen);
    }
};