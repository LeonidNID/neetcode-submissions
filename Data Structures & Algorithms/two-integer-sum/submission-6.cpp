class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // for a given num, is target-num in the array
        std::unordered_map<int, int> target_diff(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            target_diff[target - nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if(target_diff.find(num) != target_diff.end() && target_diff[num] != i)
                return {i, target_diff[num]};
        }
        return {6,7};
    }
};
