class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n);

        k %= n; // avoid redundant complete rotations
        for(int i = 0; i < n; i++) {
            int idxOrig = (n - k + i) % n; // start from k steps behind back
            res[i] = nums[idxOrig];
        }

        nums = res;    
    }
};


/*
nums=[1,2,3,4,5,6,7]
            |      |
k=3
*/