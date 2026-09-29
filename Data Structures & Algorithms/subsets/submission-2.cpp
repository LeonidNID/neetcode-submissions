class Solution {
public:
    vector<vector<int>> res; 
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        dfs(nums, path, 0);
        return res;
    }

    void dfs(vector<int>& nums, vector<int>& path, int i) {
        // base cases
        if(i == nums.size()) {
            res.push_back(path);
            return;
        }
        
        // left
        path.push_back(nums[i]);
        dfs(nums, path, i+1);

        // right
        path.pop_back();
        dfs(nums, path, i+1);
    }
};
