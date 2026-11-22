class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        std::rotate(nums.begin(), nums.end() - (k % nums.size()), nums.end());
    }
};


/*
nums=[1,2,3,4,5,6,7]
k=3

[1,2,3,4,5,6,7]
[7,1,2,3,4,5,6]
...

*/