class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        std::vector<pair<int,int>> numFreq;
        for(const auto& [number, freq] : mp) {
            numFreq.push_back({number, freq});
        }

        std::partial_sort(numFreq.begin(), numFreq.begin()+k, numFreq.end(), 
            [](const auto& a, const auto& b){
                return a.second > b.second;
            });

        std::vector<int> res(k);
        for(int i = 0; i < k; i++) {
            res[i] = numFreq[i].first;
        }

        return res;
    }
};
