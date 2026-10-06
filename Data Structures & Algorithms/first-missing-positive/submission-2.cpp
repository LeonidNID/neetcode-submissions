class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        erase_if(nums, [](int n) {return n < 1;});
        if(nums.empty() || *nums.begin() > 1) return 1; // Base case 

        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i+1] - nums[i] > 1) return nums[i] + 1;
        }
        return nums.back() + 1;
    }
};

/*
lowest = 3
lowestOverwrite = 4
[1,2,3,4,7,3,1]

PROBLEM:
lowest = 1
[1,2,4,5,6,3,1]

lowest = 3
[1,2,4,5,6,3,1]
...
lowest = 4
[1,2,3,3,3,3,1]

*/

/*
Given:
UNSORTED int array nums, return smallest possible int not in nums

O(n) time
O(1) space!

missing = 3
[1,2,4,5,7,3,1]
           |
    How to know here that 6 is next missing?

Hash set that we erase from and add to?
Could also grow with N..


Idea: AUXILIARY space → I _can_ use the array for state!
Set to the lowest number not seen

[1,2,4,5,6,3,1]
[2,3,5,6,7,7,7]


lowestNotSeen = 1
[4,1,2]

[1,2,3]


[4,2,3,5,6,2,1]


*/