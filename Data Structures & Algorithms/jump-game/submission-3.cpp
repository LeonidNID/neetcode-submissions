class Solution {
public:
    // consider [2,5,0,0] 
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
