class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> path;
        dfs(nums, path, target, 0);
        return res;
    }

    void dfs(vector<int>& nums, vector<int>& path, int target, int i) {
        // base cases
        if(target == 0) { res.push_back(path); return;}
        if(target < 0 || i >= nums.size()) return;

        // left
        path.push_back(nums[i]);
        dfs(nums, path, target - nums[i], i);

        path.pop_back();
        dfs(nums, path, target, i+1);
    }
};
