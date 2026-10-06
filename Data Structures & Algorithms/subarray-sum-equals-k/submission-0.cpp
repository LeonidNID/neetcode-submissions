class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Build prefix sum
        for(int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i-1];
        }

        // Iterate over 1 
        int res = 0;
        unordered_map<int, int> freq;
        freq[0] = 1; // Base case empty!
        for(int i = 0; i < nums.size(); i++) {
            int target = nums[i] - k;

            if(freq.find(target) != freq.end()) {
                res += freq[target];
            }

            freq[nums[i]]++;
        }
        return res;
    }
};

/*
N<=2e4 => 

[2,-1,1,2]

2 -1  1  2
2, 1, 2, 4

if nums[r] - nums[l] == k => subarr from r to l-1 = k


*/