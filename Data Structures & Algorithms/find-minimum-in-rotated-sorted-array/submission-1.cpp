class Solution {
public:
    int findMin(vector<int> &nums) {
        int res = nums[0];
        int l = 0;
        int r = nums.size() - 1;

        while(l <= r) {
            if(nums[l] < nums[r]) {
                res = min(res, nums[l]);
                break;
            }
            int mid = l + (r - l) / 2;
            res = min(res, nums[mid]); // catch middle = smallest

            if(nums[l] > nums[mid]) { // We are in sorted portion => search left
                r = mid - 1; // make right smaller => middle shifts left
            } else { // nums[l] < nums[mid]    // We are outside sorted port => right
                l = mid + 1; // make l bigger => middle shifts right
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