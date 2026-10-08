class Solution {
public:
    //unordered_map<int, int> memo; // Number of coints to make amount at idx
    const long long INF = 1e10 + 67;

    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<long long> dp(amount+1,INF);
        dp[0] = 0;

        for(int a = 0; a <= amount; a++) {
            for(const long long coin : coins) { // ll important here
                if(a + coin <= amount) {
                    dp[a+coin] = min(dp[a+coin], dp[a] + 1L);
                }
            }
        }

        return dp[amount] == INF ? -1 : dp[amount];
    }
};

/*
coins = [1,5,10], amount = 12
[0,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF]
[0,1  ,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF]
*/