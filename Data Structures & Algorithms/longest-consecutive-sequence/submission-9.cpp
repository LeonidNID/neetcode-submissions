class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        set<int> s;
        for(const auto& num : nums) {s.insert(num);}

        // -10^9 <= nums[i] <= 10^9
        int runningSeq = 1;
        int res = 1;
        // for(int i = *s.begin(); i < s*.rbegin(); i++) {}
        for(const auto& num : s) {
            if(s.contains(num+1)) {runningSeq++;}
            else {
                res = max(res, runningSeq);
                runningSeq = 1;
            }
        }

        return res;
    }
};

/*
1 greater than the previous element.
Does not have to be consecutive
[1,2,67,3] => 3 because of 1,2,3


[1,2,1e9,3]

*/