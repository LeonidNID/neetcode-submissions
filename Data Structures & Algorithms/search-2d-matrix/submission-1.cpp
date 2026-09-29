class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // search correct row first
        int l = 0;
        int r = matrix.size() - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(matrix[mid][0] > target) {
                r = mid - 1;
            } else if(matrix[mid][matrix[mid].size()-1] < target) {
                l = mid + 1;
            } else { // regular binary search in the row
                int li = 0;
                int ri = matrix[mid].size() - 1;
                while(li <= ri) {
                    int midi = li + (ri - li) / 2;
                    if(matrix[mid][midi] > target) {
                        ri = midi - 1;
                    } else if(matrix[mid][midi] < target) {
                        li = midi + 1;
                    } else {
                        return true;
                    }
                }
                return false;
            }
        }
        return false;
    }
};
