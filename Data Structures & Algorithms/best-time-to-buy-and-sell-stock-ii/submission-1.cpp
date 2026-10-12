class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total = 0;
        for(int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i-1];
            if(diff > 0) total += diff;;
        }

        return total;
    }
};

/*
[7, 1,5, 3,6, 4]
[0,-6,4,-2,3, -2]
*/