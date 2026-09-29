class Solution {
public:
    // O(n^2) time, O(1) space
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());

        // O(n^2) suggested:
        for(int i = 0; i < (int)nums.size() - 2; i++) { // Now we have a 2pointers
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int left = i+1;
            int right = nums.size() - 1;
            while(left < right) { // O(n) loop
                int sum = nums[i] + nums[left] + nums[right];
                if(sum < 0) left++; // indices must be unique
                else if(sum > 0) right--;
                else if(sum == 0) {
                    ret.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left+1]) left++;
                    while (left < right && nums[right] == nums[right-1]) right--;
                    left++; 
                    right--;
                };
            }
        } 
        return ret;
    }
};

/*
[-1,0,1,2,-1,-4]
-> [-4, -1, -1, 0, 1, 2]

WE have 2sum sorted: converging pointers approach
[-4, -1, -1, 0, 1, 2]
  |                |
-2 > 1 => left++

[-4, -1, -1, 0, 1, 2]
      |            |
-2 > 1 => left++



*/