class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int res = 0;
        int prevEnd = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++) {
            int start   = intervals[i][0];
            int end     = intervals[i][1];

            if(start >= prevEnd) {
                prevEnd = end;
            } else { // We have an overlap!
                res++; // Need to remove one
                prevEnd = min(end, prevEnd); // Greedy: shortest
            }
        }

        return res;
    }
};

/*
Given vector of vectors with 2 entries start, end
N <= 10^5 (O(nlogn)) -> sorting feasible

Return max number of intervals removed so all are non overlapping

Idea 1: 
maxOverlapping - 1;

Can we break this. Try 2 overlapping in interval of longer

[[0,2],[1,3],[2,4],[3,5],[4,6]]:

                [.......]
            [.......]
        [.......]
    [.......]
[.......]
0   1   2   3   4   5   6

*/