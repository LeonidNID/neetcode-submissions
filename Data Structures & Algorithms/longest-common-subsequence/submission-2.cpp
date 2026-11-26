class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int res = 0;
        if(text2.size() < text1.size()) swap(text1, text2); // text 1 shorter!
        int m = text1.size();
        int n = text2.size();

        // dp setup
        vector<vector<int>> dp(m, vector<int>(n, 0));
        bool found1 = false;
        for(int i = 0; i < m; i++) { 
            if(text1[i] == text2[0]) found1 = true; 
            if(found1) dp[i][0] = 1;
        }
        bool found2 = false;
        for(int i = 0; i < n; i++) { 
            if(text2[i] == text1[0]) found2 = true; 
            if(found2) dp[0][i] = 1;
        }

        // push dp
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(text1[i] == text2[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1; // diagonal cell excludes both current characters
                   // cout << "Equal found at: (" << i << ", " << j << ") = " << text1[i] << "\n"; 
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }    
        }    

        return dp[m-1][n-1];
    }
};
