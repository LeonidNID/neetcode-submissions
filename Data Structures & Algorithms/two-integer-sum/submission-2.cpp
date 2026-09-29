class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> hash;
        for(int i = 0; i < (int)nums.size(); i++) {
            hash.try_emplace(nums[i], i);
        }
        for(int i = 1; i < (int)nums.size(); i++) {
            int difference = target - nums[i];
            if(hash.contains(difference) && hash[difference] != i) {
                if(hash[difference] < i) return {hash[difference], i};
                return {i, hash[difference]};
            }
        }
    }
};
