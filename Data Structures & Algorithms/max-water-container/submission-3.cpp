class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxHeight = 0;
        int l = 0;
        int r = heights.size() - 1;

        while(l <= r) {
            int distance = (r - l) * min(heights[r], heights[l]);
            maxHeight = max(maxHeight, distance);
            if(heights[l] <= heights[r]) l++;
            else {r--;}
        }

        return maxHeight;
    }
};

/*
WE dont need to find the highest and second highest container We need to
MAXIMIZE: (right - left) * min(height[left] - heights[right])

GREEDY !

[1,7,2,5,4,7,3,6]
-> 

*/
