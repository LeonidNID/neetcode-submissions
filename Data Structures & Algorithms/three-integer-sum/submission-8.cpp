class Solution {
public:
    // O(n^2) time, O(1) space
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        // nums.size()-2 because l and r come after i!
        for(int i = 0; i < nums.size() - 2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue; // Duplication guard

            // Here do standard 2sum 
            // What l and r sum to target = -nums[i]?
            int l = i + 1;
            int r = nums.size() - 1;

            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum > 0) {r--;}
                if(sum < 0) {l++;}
                
                if(sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while(l < r && nums[l] == nums[l+1]) {l++;}
                    while(l < r && nums[r] == nums[r-1]) {r--;}
                    r--;
                    l++;
                }
            }

        }
        return res;
    }
};

/*
[-4, -1, -1, 0, 1, 2]
      |      |     |


Duplication guard at start of for(int i = 0; i < nums.size() - 2; i++) AND 
when sum of 3 indices is 0: move left fwd when n[l] = n[l+1] and reverse for right

[-1,0,1,2,-1,-4]
->
[-4, -1, -1, 0, 1, 2]

WE have 2sum sorted: converging pointers pproach
[-4, -1, -1, 0, 1, 2]
|                |
-2 > 1 => left++

[-4, -1, -1, 0, 1, 2]
      |            |
-2 > 1 => left++

[-1 0 1 2]



*/