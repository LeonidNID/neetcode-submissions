class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> numSet;
        for(int i = 0; i < (int)nums.size(); i++) {
            numSet.insert(nums[i]);
        }
        return nums.size() != numSet.size();
    }
};