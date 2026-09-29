class Solution {
public:
    int climbStairs(int n) {
    if (n <= 1)
        return n;

    std::vector<long long> dp(n + 1);

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
    }
};

/*
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1); 
        dp[1] = 1;
        for(int i = 0; i < n; ++i) {
            for(int s : {1,2}) { // Transitions
                if(i + s <= n)
                    dp[i+s] += 1;
            }
        }
        return dp[n];
    }
};

*/