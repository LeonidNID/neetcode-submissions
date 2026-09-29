class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, nums, path, target, 0);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& path, int target, int i) {
        // base case
        int pathSum = std::accumulate(path.begin(), path.end(), 0);
        if(pathSum >= target || i >= nums.size()) {
            if(pathSum == target && std::find(res.begin(), res.end(), path) == res.end()) { 
                res.push_back(path); 
            }
            return;
        }

        // left
        path.push_back(nums[i]);
        dfs(res, nums, path, target, i+1);

        // re-use
        dfs(res, nums, path, target, i);

        // right
        path.pop_back();
        dfs(res, nums, path, target, i+1);
    }
};
