class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> diff;

        for(int i = 0; i < nums.size(); i++) {
            if(diff.contains(target - nums[i])) {
                return {diff[target - nums[i]], i};
            }
            diff[nums[i]] = i;
        }
        return {};
    }
};