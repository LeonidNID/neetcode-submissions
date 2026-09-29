class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;

        for(int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }

        vector<vector<int>> buckets(nums.size()+1);

        for(const auto& [value, freq] : hash) {
            buckets[freq].push_back(value);
        }

        vector<int> ret{};
        for(int i = buckets.size()-1; i > 0; i--) {
            if(!buckets[i].empty()) {
                for(const auto& num: buckets[i]) {
                    ret.push_back(num);
                    if(ret.size() == k) return ret;
                }
            }
        }
        return ret;
    }
};
