class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix = {1};
        vector<int> suffix = {1};
        for(int i = 1; i < nums.size(); i++) {
            prefix.push_back(nums[i-1] * prefix.back());
        }

        for(int i = nums.size() - 1; i > 0; i--) {
            suffix.push_back(nums[i] * suffix.back());
        }
        reverse(suffix.begin(), suffix.end());

        vector<int> res(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            res[i] = prefix[i] * suffix[i];
        }

        return res;
    }
};
