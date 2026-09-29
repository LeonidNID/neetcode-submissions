class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        dfs(candidates, path, target, 0);
        return res;
    }

    void dfs(vector<int>& c, vector<int>& path, int target, int i) {
        if(target == 0) {res.push_back(path); return;}
        if(target < 0 || i >= c.size()) {return;}

        path.push_back(c[i]);
        dfs(c, path, target - c[i], i + 1);
        path.pop_back();

        // The trick: skip all duplicate candidates!
        int j = i;
        while(j < c.size() && c[i] == c[j]) { j++; }
        dfs(c, path, target, j);
    }
};



/*
1) HOW do I not store duplicates?

2) How does one avoid duplicates in backtracking in general?

*/