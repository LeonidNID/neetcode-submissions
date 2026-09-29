class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> dp(n+1, 0);
        dp[0] = nums[0];
        dp[1] = nums[1];

        for(int h = 2; h < n; h++) { 
            for(int i = 0; i <= h-2; i++) {
                dp[h] = max(dp[h], dp[i] + nums[h]);
            }
        }

        return max(dp[n-1], dp[n-2]);
    }
};
