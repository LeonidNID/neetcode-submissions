class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Load all into standard max heap
        std::priority_queue<int> pq(stones.begin(), stones.end());

        while(pq.size() > 1) {
            // Take top 2 stones
            int topStone = pq.top(); 
            pq.pop();

            int top2Stone = pq.top(); 
            pq.pop();

            // Ordering guaranteed bc of max heap property
            if(topStone > top2Stone) {
                pq.push(topStone - top2Stone);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};
