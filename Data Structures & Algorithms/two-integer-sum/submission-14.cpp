class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> prev;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];

            if (prev.find(diff) != prev.end() && prev[diff] != i) {
                return { prev[diff],i};
            } 
            prev[nums[i]] = i;
        }
        return {};
    }
};