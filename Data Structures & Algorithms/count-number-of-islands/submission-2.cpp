class Solution {
public:
    int res = 0;
    int rows = 0, cols = 0;
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector(cols, false));
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    bfs(grid, visited, i, j);
                    res++;
                }
            }    
        }

        return res;
    }
    
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, 
    int i, int j) {
        if(i >= rows || i < 0 || j >= cols || j < 0
           || grid[i][j] == '0') return; // OOB base-case

        visited[i][j] = true;

        // Explore all directions
        if(i < rows-1 && !visited[i+1][j]) bfs(grid, visited, i+1, j);
        if(i > 0 && !visited[i-1][j]) bfs(grid, visited, i-1, j);
        if(j < cols-1 && !visited[i][j+1]) bfs(grid, visited, i, j+1);
        if(j > 0 && !visited[i][j-1]) bfs(grid, visited, i, j-1);
    }

};

/*
Recursive BFS function to check all directions. 
No need to track leader positons, just use vector<vector<bool>> visited(rows, vector<bool>(cols, false));

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