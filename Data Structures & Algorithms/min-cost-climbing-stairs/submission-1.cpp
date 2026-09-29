class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        const int INF = 1e9;
        vector<int> dp(n+1, INF); // Inf because we minimize 

        // start at idx 0 or idx 1
        dp[0] = 0;
        dp[1] = 0; 

        // dp[i] == "Min cost to get to i"

        for(int s = 0; s <= n; s++) { // steps
            if(s < n) {
                dp[s+1] = min(dp[s+1], dp[s] + cost[s]);
                //cout << "dp[s] + cost[s] = " << dp[s] << " + " << cost[s] << "\n";
            }
            if(s < n-1) {
                dp[s+2] = min(dp[s+2], dp[s] + cost[s]);
                //cout << "dp[s] + cost[s] = " << dp[s] << " + " << cost[s] << "\n";
            }
        }

        return dp[n]; // min cost to get to n (top)
    }
};

/*
NOT a greedy problem!

start at idx 0, cost 0
while(i < n+1) "still on stairs"
go to step 0 with cost cost[0] or step 1 with cost cost[1]


*/