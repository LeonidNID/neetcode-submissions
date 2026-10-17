class Solution {
public:
    vector<vector<int>> memo;
    int uniquePaths(int m, int n) {
        memo.resize(m, vector<int>(n, -1));
        for(int i = 0; i < n; i++) { memo[0][i] = 1; } // First row 1
        for(int i = 0; i < m; i++) { memo[i][0] = 1; } // First col 1

        return dfs(m-1, n-1, m, n);
    }

    int dfs(int i, int j, int m, int n) {
        if(i >= m || j >= n) return 0;
        if(memo[i][j] != -1) return memo[i][j];
    
        return memo[i][j] = dfs(i, j-1, m, n) + dfs(i-1, j, m, n);
    }
};
