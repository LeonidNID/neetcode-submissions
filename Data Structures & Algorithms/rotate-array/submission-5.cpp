class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n; // avoid redundant complete rotations

       // int l = 0;
        //int r = n - k - 1;
        int swaps = 0;
        while(swaps < k) {
            int back = nums.back();
            nums.pop_back();
            nums.insert(nums.begin(), back);
            swaps++;
            //l++;
            //r = (r + 1) % n;
        }
    }
};


/*
nums=[1,2,3,4,5,6,7]
k=3

[1,2,3,4,5,6,7]
[7,1,2,3,4,5,6]

*/