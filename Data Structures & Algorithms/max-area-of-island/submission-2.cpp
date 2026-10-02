class Solution {
public:
    int rows = 0, cols = 0;
    int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int area = 0;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) {
                    area = max(area, dfs(grid, i, j));
                }
            }    
        }
        return area;
    }

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == 0) 
            return 0; // base case

        grid[i][j] = 0;
        int res = 1;
        for(int DONT_SHADOW_i = 0; DONT_SHADOW_i < 4; DONT_SHADOW_i++) {
            res += dfs(grid, i + directions[DONT_SHADOW_i][0], j + directions[DONT_SHADOW_i][1]);
        }

        return res;
    }
};

/*

*/