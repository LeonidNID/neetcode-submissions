class Solution {
public:
    // O(n^2) time, O(1) space
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        std::sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue; // duplication guard

            int l = i+1;
            int r = (int)nums.size() - 1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum > 0) { r--; }
                else if(sum < 0) { l++; }
                else if(sum == 0) {
                    ret.push_back({nums[i], nums[l], nums[r]});
                    while(l < r && nums[l] == nums[l+1]) { l++; } // duplication guard
                    while(l < r && nums[r] == nums[r-1]) { r--; } // duplication guard
                    l++;
                }
            }
        }
        return ret;
    }
};

/*
IMPORTANT: Duplication  checks at the start of inner loop and after adding element to result vector

[-1,0,1,2,-1,-4]
-> [-4, -1, -1, 0, 1, 2]

WE have 2sum sorted: converging pointers pproach
[-4, -1, -1, 0, 1, 2]
|                |
-2 > 1 => left++

[-4, -1, -1, 0, 1, 2]
      |            |
-2 > 1 => left++

[-1 0 1 2]



*/