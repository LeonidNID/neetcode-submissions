class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        int n = s.size();
        //vector<int> dp(n+1, 0); // initialize to s.size?

        // Iterate over the string with index i and treat the current character as the center
        for(int i = 0; i < n; i++) {
            // dp[i]++; // Always add 1 each step because we know all are valid
            // dp[i] += scanPalindromes(s.substr(0, i+1)); 

            // Even
            int l = i;
            int r = i;
            while(l >= 0 && r < n && s[l] == s[r]) {
                res++;
                l--;
                r++;
            }

            // Odd
            l = i;
            r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]) {
                res++;
                l--;
                r++;
            }
        }

        return res;
    }

};

/*
Counting problem
s.length <= 1000 (Only valid lowercase)

abc => a, b, c (3)
aba => a, b, a, aba (4)
aaa => a, a, a, aa (1,2), aa (2,3), aaa (6)
"x" => 1

Idea: 
Bottom up dp
Loop through string

check at idx i we have all duplicates.
=> O(n^2) (fine)
O(1) space recommended!
*/
