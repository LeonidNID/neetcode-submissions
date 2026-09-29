class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) { // constructor
        m_k = k;
        for(int i = 0; i < nums.size(); i++) { // init pq
            pq.push(nums[i]);
            if(pq.size() > m_k) pq.pop();
        }
    }
    
    int add(int val) { // Return k-th largest here
        pq.push(val);
        if(pq.size() > m_k) pq.pop();

        return pq.top();
    }

private:
    int m_k{};
    std::priority_queue<int, vector<int>, greater<>> pq; // Min heap
};

/*
What do I need to return where?
-> int in add

Key Insight: Keep the queue size 3: return top() (min element = 3rd largest)
2 3 4 
|    

5 5 8


Bottom of max heap needed!
How can we do this?
=> Min heap of size 3

1 2 3 3 3 5 6
        |
Min Heap (top = smallest)

*/