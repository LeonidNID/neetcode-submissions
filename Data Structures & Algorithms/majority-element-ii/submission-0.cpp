class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size() / 3;
        unordered_map<int, int> mp;
        for(int n : nums)  {mp[n]++;}

        vector<int> res;
        for(const auto [num, freq] : mp) {
            if(freq > n) res.push_back(num);
        }   

        return res;
    }
};