class Solution {
public:
    int findMin(vector<int> &nums) {
        int res = nums[0];
        int l = 0;
        int r = nums.size() - 1;

        while(l <= r) {
            if(nums[l] < nums[r]) return nums[l]; // Already sorted

            int mid = l + (r - l) / 2;
            res = min(nums[mid], res);

            if(nums[l] > nums[mid]) { // correct array search left
                r--;
            } else {
                l++;
            }
        }
        return res;
    }
};


/*


89|1234567
     | 

Here, the array is rotated twice, resulting in two sorted segments: [3, 4] and [1, 2]. And the minimum element will be the first element of the right segment. Can you do a binary search to find this cut? 
*/