class Solution {
public:
    static long long dist2(const vector<int>& p) {
        return 1LL * p[0] * p[0] + 1LL * p[1] * p[1];
    }

    //double dist2(vector<int>& point) {
    //    return sqrt(pow(*point.begin(), 2) + pow(*point.end(), 2));
    //}

    struct Cmp {
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            return dist2(a) < dist2(b);          // '<' → farthest on top
        }
    };
    

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Cmp> pq; 
        for(const auto& p : points) {
            pq.push(p);
            if ((int)pq.size() > k) pq.pop(); // pop the farthest
        }

        vector<vector<int>> res;
        while(!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }

};
