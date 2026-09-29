class Solution {
public:
    int res = 0;
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<pair<int,int>>> leaders(grid.size(), vector<pair<int,int>>(grid[0].size(), {-1, -1})); // O(m * n) space

        for(long m = 0; m < grid.size(); m++) { // O(m * n) time
            for(long n = 0; n < grid[0].size(); n++) {
                if(grid[m][n] == '1' && (leaders[m][n] == pair{-1, -1})) {
                    bfs(grid, leaders, m, n);
                    res++;
                }
            }    
        }

        return res;
    }

    void bfs(vector<vector<char>>& grid, 
             vector<vector<pair<int,int>>>& leaders, int i, int j) {
        if(i < 0 || j < 0 || i > grid.size() - 1 || j > grid[0].size() - 1 
           || leaders[i][j] != pair{-1, -1} || grid[i][j] == '0') return;   

        leaders[i][j] = {i,j};

        // Look in all directions: top, bottom, left, right
        bfs(grid, leaders, i-1, j);
        bfs(grid, leaders, i+1, j);
        bfs(grid, leaders, i, j+1);
        bfs(grid, leaders, i, j-1);

    }
};

/*
How do I know what islands are connected?
-> Start top left -> do bfs

What is the bfs step?
-> check if surrounding chars are also 1

How do avoid forming new redundant groups?
-> track visited

How?
-> Leader node

How to determine leaders nodes?
-> as bfs starts, start node e.g. (0,1) is leader



*/