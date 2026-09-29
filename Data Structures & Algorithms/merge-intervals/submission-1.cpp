class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return intervals;
        sort(intervals.begin(), intervals.end()); // sorted by start time

        vector<vector<int>> merged;
        
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] <= intervals[i-1][1]) {
                intervals[i][0] = intervals[i-1][0];
                intervals[i][1] = max(intervals[i-1][1], intervals[i][1]);
            } else {
                merged.push_back({intervals[i-1][0], intervals[i-1][1]});
            }
        }   
        merged.push_back({intervals.back()[0], intervals.back()[1]});

        return merged; 
    }
};
