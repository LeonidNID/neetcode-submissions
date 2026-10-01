class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, {}, 0);
        return res;
    }

    void dfs(vector<int>& nums, vector<int> path, int i) {
        // base case
        if(i == nums.size()) {
            if(!std::ranges::contains(res, path))
                res.push_back(path);
            return;   
        }

        // left
        path.push_back(nums[i]);
        // int j = i;
        // while(j < nums.size() && nums[i] == nums[j]) {
        //    j++;
        // }
        dfs(nums, path, i+1);

        // right
        path.pop_back();
        dfs(nums, path, i+1);
    }
};
