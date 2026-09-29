class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++) {
            if(!freq.contains(nums[i])) {
                freq[nums[i]] = 1;
            } else {
                freq[nums[i]]++;
            }
        }
        std::vector<std::pair<int, int>> sortedArr(freq.begin(), freq.end());
        std::sort(sortedArr.begin(), sortedArr.end(), 
                  [](const auto& a, const auto& b){return a.second > b.second;});
        vector<int> res;
        for(int i = 0; i < k; i++) {
            res.push_back(sortedArr[i].first);
        }
        return res;
    }
};
