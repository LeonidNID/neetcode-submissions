class Solution {
public:
    unordered_map<int, int> memo; // unordered map bc coin value spans INT
    const int INF = 1e9 + 8;
    int coinChange(vector<int>& coins, int amount) {
        int minCoins = dfs(coins, amount);
        return minCoins == INF ? -1 : minCoins;
    }

    int dfs(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        if(memo.contains(amount)) return memo[amount];

        int res = INF;
        for(const int c : coins) {
            if(amount - c >= 0) {
                int bestSoFar = dfs(coins, amount - c);
                if(bestSoFar < INF) {
                    res = min(res, bestSoFar + 1);
                }
            }
        }
        
        memo[amount] = res;
        return res;
    }
};
