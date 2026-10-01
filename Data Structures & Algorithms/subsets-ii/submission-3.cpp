class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, {}, 0);
        return res;
    }

    void dfs(vector<int>& nums, vector<int> path, int i) {
        res.push_back(path);
        for(int j = i; j < nums.size(); j++) {
            if(j > i && nums[j] == nums[j - 1]) continue;

            path.push_back(nums[j]);
            dfs(nums, path, j + 1);
            path.pop_back();
        }
    }
};
