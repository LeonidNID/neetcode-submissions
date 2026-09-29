class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxarea = 0;
        int left= 0;
        int right = heights.size() - 1;

        // O(n) time, O(1) space
        while(left <= right) {
            int distance = right - left;
            int area = distance * min(heights[left], heights[right]);
            maxarea = max(maxarea, area);

            if(heights[left] <= heights[right]) left++;
            else right--;
        }
        return maxarea;
    }
};

/*
WE dont need to find the highest and second highest container We need to
MAXIMIZE: (right - left) * min(height[left] - heights[right])

GREEDY !

[1,7,2,5,4,7,3,6]
-> 

*/
