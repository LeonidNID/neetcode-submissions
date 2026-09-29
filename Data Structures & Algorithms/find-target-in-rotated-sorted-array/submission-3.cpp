class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(target == nums[mid]) return mid;

            if(nums[l] > nums[mid]) { // We are in sorted portion 
                if(target < nums[mid] || target > nums[r]) r = mid - 1;
                else l = mid + 1;
            } else { // nums[l] < nums[mid]    // We are outside sorted port => right
                if(target > nums[mid] || target < nums[l]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }
};
