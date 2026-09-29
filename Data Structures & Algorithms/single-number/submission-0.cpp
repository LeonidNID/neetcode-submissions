class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorInt = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            xorInt ^= nums[i];
        }
        return xorInt;    
    }
};

/*
011 XOR 010 = 001



*/