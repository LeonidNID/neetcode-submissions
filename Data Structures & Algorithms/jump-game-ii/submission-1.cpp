class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        
        int goal = nums.size() - 1;
        int minJumps = 0;

        // Idea: Greedily find farthest viable number
        while(goal != 0) {

            // Find farthest from current node that fits
            int farthest = goal - 1;
            for(int i = goal - 1; i >= 0; i--) {
                if(i + nums[i] >= goal) farthest = i;
            }
            goal = farthest;
            minJumps++;
        }

        return minJumps;
    }
};

/*
[2,4,1,1,1,1]
   ^ max length of jump from here
*/