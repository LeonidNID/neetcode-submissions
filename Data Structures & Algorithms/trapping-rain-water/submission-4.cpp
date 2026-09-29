class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int l = 0;
        int r = (int)height.size() - 1;
        int leftmax = height[l];
        int rightmax = height[r];

        while(l < r) {
            if(leftmax < rightmax) {
                l++;
                leftmax = max(height[l], leftmax);
                res += leftmax - height[l];
            }
            else {
                r--;
                rightmax = max(height[r], rightmax);
                res += rightmax - height[r];
            }
        }
        return res;
    }
};

/*
non-negative integers 
Water IN BETWEEN bars (bars gotta be there, edges dont count)

[0,2,0,3,1,0,1,3,2,1]

slow and fast move
both to 2 (first > 0)
fast moves on, ast detects 3 (>= 2)
-> track elevations idx between fast and slow
elevations[2] = heights[slow] - heights[2] = 2
-> (fast - slow) * elevations[2])
res += 



*/