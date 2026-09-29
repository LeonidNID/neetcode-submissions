class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        // Min heap (sorted by first value, distance)
        priority_queue<pair<int, int> , vector<pair<int, int>>, greater<>> pq; 
        for(long i = 0; i < points.size(); i++) {
            vector<int> v = points[i];
            int distance = v[0] * v[0] + v[1] * v[1];
            pq.push({distance, i});
        }

        while(k--) {
            pair<int, int> pointIdxPair = pq.top();
            pq.pop();
            res.push_back(points[pointIdxPair.second]);
        }

        return res;
    }

};
