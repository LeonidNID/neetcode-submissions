class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) return mid;

            if(nums[l] <= nums[mid]) { // !!
                if(nums[l] > target || target > nums[mid]) { //correct sect
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else { // nums[l] > nums[mid]
                if(target < nums[mid] || target > nums[r]) { // incorrect sect
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
};

/*
nums=[3,4,5,6,1,2] target=1
          |
*/