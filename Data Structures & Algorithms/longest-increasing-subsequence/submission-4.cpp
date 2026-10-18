class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));

        for(int i = 1; i <= n; ++i) {
            for(int j = i; j <= n; ++j) {
                int LIS = dp[i-1][j];

                if(j == n || nums[i-1] < nums[j]) {
                    LIS = max(1 + dp[i-1][i-1], LIS);
                }

                dp[i][j] = LIS;
            }    
        }

        return dp[n][n];
    }
};
