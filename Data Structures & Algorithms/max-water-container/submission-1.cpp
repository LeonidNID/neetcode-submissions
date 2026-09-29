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
            if(area > maxarea) maxarea = area; 
            if(left < right && heights[left] > heights[right]) right--;
            else left++;
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
