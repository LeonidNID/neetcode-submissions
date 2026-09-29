class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // for a given num, is target-num in the array
        std::unordered_map<int, int> nummap(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            nummap[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if(nummap.find(diff) != nummap.end() && nummap[diff] != i)
                return {i, nummap[diff]};
        }
        return {};
    }
};
