class Solution {
public:
    int res = 0;
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false)); 

        for(long m = 0; m < grid.size(); m++) { // O(m * n) time
            for(long n = 0; n < grid[0].size(); n++) {
                if(grid[m][n] == '1' && !visited[m][n]) {
                    bfs(grid, visited, m, n);
                    res++;
                }
            }    
        }

        return res;
    }

    void bfs(vector<vector<char>>& grid, 
             vector<vector<bool>>& visited, int i, int j) {
        if(i < 0 || j < 0 || i > grid.size() - 1 || j > grid[0].size() - 1 
           || visited[i][j] || grid[i][j] == '0') return;   

        visited[i][j] = true;

        // Look in all directions: top, bottom, left, right
        bfs(grid, visited, i-1, j);
        bfs(grid, visited, i+1, j);
        bfs(grid, visited, i, j+1);
        bfs(grid, visited, i, j-1);

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