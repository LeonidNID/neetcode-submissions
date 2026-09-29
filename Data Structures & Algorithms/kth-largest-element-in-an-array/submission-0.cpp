class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> pq;

        for(const auto& num : nums) {
            pq.push(num);
            if(pq.size() > k) pq.pop();
        }

        return pq.top();
    }
};

/*
Min heap of size k. k-th largest = smallest = pq.top
*/