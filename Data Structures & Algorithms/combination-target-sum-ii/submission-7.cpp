class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<int> path;
        dfs(candidates, path, target, 0, 0);
        return res;
    }

    void dfs(vector<int>& c, vector<int>& path, int target, int rSum, int i) {
        // base + append
        if(rSum == target) {
            res.push_back(path);
            return;
        }
        if(rSum > target || i >= c.size()) {
            return;
        }

        // left
        path.push_back(c[i]);
        dfs(c, path, target, rSum + c[i], i+1);

        // right
        path.pop_back();
        // Skip our duplicates in candidates like so:
        int j = i;
        while(j < c.size() && c[j] == c[i]) {j++;}
        dfs(c, path, target, rSum, j); // j is at least i+1
    }
};



/*
Sort candidates at the start. 
For the dfs: after the pop() set int j = i and skip ALL duplicates. 
c[i] == c[j] && j < c.size()

1) HOW do I not store duplicates?
2) How does one avoid duplicates in backtracking in general?

*/