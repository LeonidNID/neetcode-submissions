class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        set<pair<char, int>> squares[9];

        // n^2
        for(int row = 0; row < 9; row++) {
            for(int col = 0; col < 9; col++) { 
                if(board[row][col] == '.') continue;
                int curNum = board[row][col] - '0';
                int squareidx = (row / 3) * 3 + (col / 3);
                if(rows[row].contains(board[row][col]) ||  
                        cols[col].contains(board[row][col]) || 
                        squares[squareidx].contains({board[row][col], curNum / 3})) {
                            return false;
                        }

                // populate hashsets
                rows[row].insert(board[row][col]);
                cols[col].insert(board[row][col]);
                squares[squareidx].insert({board[row][col], curNum / 3});
            }
        }
        return true;
    }
};
