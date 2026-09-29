class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> back(nums.begin(), nums.end() - 1);
        vector<int> front(nums.begin() + 1, nums.end());

        return max(helper(back), helper(front));
    }

    int helper(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        int n = nums.size();

        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);

        for(int h = 2; h < n; h++) { 
            dp[h] = max(dp[h-1], dp[h-2] + nums[h]);
        }

        return dp.back();
    }
};
