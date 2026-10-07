class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m_matrix = matrix;
    };
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int r = row1; r <= row2; r++) {
            for(int c = col1; c <= col2; c++) {
                sum += m_matrix[r][c];
            }    
        }
        return sum;
    }

private:
    vector<vector<int>> m_matrix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

/*

*/