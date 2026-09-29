class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        vector<int> path;
        dfs(res, nums, path, target, 0);
        
        vector<vector<int>> v;
        for(const auto& r : res) {v.push_back(r);}
        return v;
    }

    void dfs(set<vector<int>>& res, vector<int>& nums, vector<int>& path, int target, int i) {
        int total = std::accumulate(path.begin(), path.end(), 0);
        
        // base case
        if(target == total) {
            res.insert(path);
        }
        if(total > target || i >= nums.size()) return;

        // left
        path.push_back(nums[i]);
        dfs(res, nums, path, target, i);

        path.pop_back();
        dfs(res, nums, path, target, i+1);

    }
};
