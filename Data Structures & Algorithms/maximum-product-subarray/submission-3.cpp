class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMin = 1, curMax = 1;

        for (int num : nums) {
            int tmp = curMax * num;
            curMax = max(max(tmp, num * curMin), num);
            curMin = min(min(tmp, num * curMin), num);
            res = max(res, curMax);
        }
        return res;
    }
};
/*
Given an array of numbers(+ and -) like [2, 4, -3, 5]
Find the maximum CONTIGUOUS subarray that the sum is maximal.

Here: 
[2, 4, -3, 5] => 8. [2,4] ([2,4,5] NOT ALLOWED - not contiguous)
[-3, 0, -2] => 0. All others negavtive
[1,2,3] => 6

[1,2]
[1,2,8] Take
[1,2,1] Take
[1,2,0] Dont take. RESET!
[1,2,-8]

APPROACH: Max so Dp initialized with -INF
nums =  [2, 4, -3, 5]
dp =    [-, -, - , -]
dp =    [2, -, - , -]
dp =    [2, 8, - , -]
dp =    [2, 8,  8, -]
dp =    [2, 8,  8, 40] WRONG. We do 8 * 5 but the whole thing would be -120

*/
