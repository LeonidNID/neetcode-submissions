class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;

        for(int i = goal - 1; i >= 0; i--) {
            if(i + nums[i] >= goal) {
                goal = i;
            }
        }    
        return goal == 0;
    }
};

/*
Array like nums=[1,2,0,1,0] (length 1 to 1000)

At index i we can jump UP TO nums[i] fields but don't have to.
at nums[0] we can only jump 1 so ofc jump 1
at nums[1] we can jump up to 2 so either 1 or 2.
Jumping 1 would land us on a 0 field so we jump 2
nums[3] is 1, easy choice, we jump 1 and are at idx nums.length() - 1. True.

What we do NOT want to do:
- always jump the max - counterExample: [1,2,2,0,0]
- Land on 0 unless that is target idx

Greedy idea:
BACKWARDS:

from last idx, what positions can reach the start?

*/