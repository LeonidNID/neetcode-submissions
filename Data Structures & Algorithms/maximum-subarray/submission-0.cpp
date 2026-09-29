class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum{nums[0]};
        int curSum{nums[0]};

        for(long i{1}; i < nums.size(); i++) {
            curSum = max(nums[i], curSum + nums[i]);
            if(curSum > maxSum) maxSum = curSum;
        }

        return maxSum;
    }
};
