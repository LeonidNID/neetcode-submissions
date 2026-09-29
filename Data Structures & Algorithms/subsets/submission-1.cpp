class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, path, nums, 0);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& path, vector<int>& nums, int index) {
        // Leaf reached
        if(index >= nums.size()) {
            res.push_back(path); // Add the leaf value
            return;
        }

        // Left side of tree (add values)
        path.push_back(nums[index]);
        dfs(res, path, nums, index + 1);

        // Right side of tree (don't include values)
        path.pop_back();
        dfs(res, path, nums, index + 1);
    }
};
