class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqTable;
        for(const auto& num : nums) {freqTable[num]++;}

        priority_queue<pair<int,int>> pq; // standard max heap
        for(const auto& [num, freq] : freqTable) {
            pq.push({freq, num}); // automatically sortedd by freq
        }

        vector<int> res;
        while(k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
