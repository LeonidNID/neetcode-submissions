class Solution {
public:
    bool res = false;
    bool exist(vector<vector<char>>& board, string word) {
        cout << "Calling main function\n";
        for(long i{0}; i < board.size(); i++) {
            for(long j{0}; j < board[i].size(); j++) {
                if(board[i][j] == word[0]) { // Starting point found
                    cout << "Starting to look at position i=" << i << ", j =" << j << "\n";
                    std::string s(1, word[0]);
                    set<pair<int,int>> visited;
                    visited.insert({i,j});
                    dfs(board, visited, word, s, i, j);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& board, set<pair<int,int>>& visited,
             string& word, string& cur, int row, int col) {
        if(res) return;
        //cout << "Calling dfs function with the word " << cur << "\n";
        //cout << "Exploring position row=" << row << ", col =" << col << "\n";
        
        visited.insert({row, col});
        if(cur == word) {res = true; return;}
        // Condition to stop search (we added wrong letter)
        //cout << "cur[cur.size() - 1] == " << cur[cur.size() - 1] << " word[cur.size() - 1] = " << word[cur.size() - 1] << "  |  Exiting: " << (cur[cur.size() - 1] != word[cur.size() - 1]) << "\n";
        if(cur.size() > word.size() || cur[cur.size() - 1] != word[cur.size() - 1]) {
            visited.erase({row, col});
            return;
        }
        // Explore all 4 directions (top, bottom, right, left)
        if(row > 0 && !visited.contains({row-1, col})) { // top
            //cout << "Flag1\n";
            cur += board[row-1][col];
            dfs(board, visited, word, cur, row-1, col);
            cur.pop_back();
        }
        if(col < board[0].size() - 1 && !visited.contains({row, col+1})) { // right
            //cout << "Flag3\n";
            cur += board[row][col+1];
            dfs(board, visited, word, cur, row, col+1);
            cur.pop_back();

        }
        if(row < board.size() - 1 && !visited.contains({row+1, col})) { // bottom
            //cout << "Flag2\n";
            cur += board[row+1][col];
            dfs(board, visited, word, cur, row+1, col);
            cur.pop_back();

        }
        if(col > 0 && !visited.contains({row, col-1})) { // left
            //cout << "Flag4\n";
            cur += board[row][col-1];
            dfs(board, visited, word, cur, row, col-1);
            cur.pop_back();

        }
        visited.erase({row, col});
    }
};
