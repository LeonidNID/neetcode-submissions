class Solution {
public:
    int INF = 2147483647;
    int ROWS, COLS;
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        queue<pair<int,int>> q;
        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        while(!q.empty()) { // Multi-source BFS
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) { // Try exploring all 4 directions
                int r = row + directions[i][0];
                int c = col + directions[i][1];

                if(r < 0 || c < 0 || r >= ROWS || c >= COLS ||
                   grid[r][c] < INF) { // Count lower of eq. already found
                    continue;
                }

                grid[r][c] = grid[row][col] + 1;

                q.push({r, c});
            }
        }

    }
};
