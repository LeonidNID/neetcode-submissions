class Solution {
public:
    int ROWS;
    int COLS;
    int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(grid[r][c] == 1) { // start from rotten fruits
                    fresh++;
                }
            }
        }

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(grid[r][c] == 2) { // start from rotten fruits
                    q.push({r,c});
                }
            }
        }

        int res = 0;
        while(!q.empty()) {

            bool newInfected = false;
            int size = q.size();
            for(int n = 0; n < size; n++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for(int i = 0; i < 4; i++) { // All 4 directions
                    int r = row + directions[i][0];
                    int c = col + directions[i][1];

                    if(r < 0 || c < 0 || r >= ROWS || c >= COLS ||
                    grid[r][c] == 0 || grid[r][c] == 2) { // Already rotten/empty
                        continue;
                    }

                    grid[r][c] = 2; // Make rotten
                    --fresh;
                    newInfected = true;
                    q.push({r,c});
                }
            }
            if(newInfected) res++;
        }

        return fresh == 0 ? res : -1;
    }

};

/*
[2,1,1]
[1,1,0]
[0,1,1]

[2,2,1]
[2,1,0]
[0,1,1]

[2,2,1]
[2,2,0]
[0,1,1]

Adding 1 to rotten count at 1, 1
Adding 1 to rotten count at 0, 2

How to avoud 2oduble counteing?

*/