class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> diffs(prices.size());
        for(int i = 1; i < prices.size(); i++) {
            diffs[i] = prices[i] - prices[i-1];
            //cout << "Adding " << prices[i] - prices[i-1] << "\n";
        }

        int totalProfit = 0;
        for(const auto& chg: diffs) {
            if(chg > 0) totalProfit += chg;
        }

        return totalProfit;
    }
};

/*
[7, 1,5, 3,6, 4]
[0,-6,4,-2,3, -2]

*/