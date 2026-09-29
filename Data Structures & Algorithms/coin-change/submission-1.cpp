class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        const long long INF = 1e10 + 8;
        vector<long long> dp(amount+1, INF);
        dp[0] = 0;

        for(int s = 0; s <= amount; s++) {
            for(const long long c : coins) {
                if(s + c <= amount) {
                    dp[s+c] = min(dp[s+c], dp[s] + 1);
                }
            }
        }

        return dp[amount] == INF ? -1 : dp[amount];
    }
};
