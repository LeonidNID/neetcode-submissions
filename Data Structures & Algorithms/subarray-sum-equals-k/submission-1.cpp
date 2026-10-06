class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        for(int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i-1]; // build prefix sum inplace
        } 

        int res = 0;
        unordered_map<int,int> freq;
        freq[0] = 1; // Base case - empty array means 0

        for(int i = 0; i < nums.size(); i++) {
            int target = nums[i] - k;

            if(freq.find(target) != freq.end()) {
                res += freq[target]; // Add all valid subarrays here
            }

            freq[nums[i]]++;
        }

        return res;
    }
};