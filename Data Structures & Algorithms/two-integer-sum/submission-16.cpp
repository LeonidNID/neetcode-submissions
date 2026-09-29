class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> prev;

        for(int i = 0; i < (int)nums.size(); i++) {
            if(prev.contains(target - nums[i])) return {prev[target - nums[i]], i};
            prev[nums[i]] = i;
        }
        return {};
    }
};