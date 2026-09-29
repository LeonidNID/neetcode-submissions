class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;

        int maxprofit = 0;
        int left = 0;
        int right = 1;
        
        int runningprofit {0};
        while(right < prices.size()) {
            runningprofit += prices[right] - prices[right-1];
            if(runningprofit < 0) {
                left = right;
                right++;
                runningprofit = 0;
            }
            else if(runningprofit >= 0) {
                cout << "Adding profit of " << runningprofit << " at left = " << left << " | right = " << right <<"\n";
                maxprofit = max(maxprofit, runningprofit);
                right++;
            }
        }
        return maxprofit;
    }
};

/*
[10,1,5,6,7,1]
  | |
*/
