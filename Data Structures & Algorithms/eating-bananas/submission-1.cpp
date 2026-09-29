class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minE = 1;
        int maxE = *max_element(piles.begin(), piles.end());
        int res = maxE;

        while(minE <= maxE) { // O(log(m))
            int midE = (maxE + minE)/2;

            long long totalHneeded = 0;
            for(int p : piles) { // O(n)
                totalHneeded += ceil(static_cast<double>(p) / midE);
            }
            
            if(totalHneeded <= h) {
                res = midE;
                maxE = midE - 1;
            } else {
                minE = midE + 1;
            }
        }
        return res;
    }
};

/*
Input: piles = [1,4,3,2], h = 9
Output: 2
sumarr(piles)/

Condition: Can eat all piles within h ours eating midE per hour.

4: 1-> 0
   4-> 0
   3-> 0
   2-> 0
3: 1-> 0
   4-> 1
   3-> 0
   2-> 0 



Input: piles = [25,10,23,4], h = 4
Output: 25

62 total, so why not 62/4 = 16?
pile has less than k bananas, you may finish eating the pile but you can not eat from another pile in the same hour.
=> 25.

So start at maxelement(piles), work down towards 1.

numEntries/h
[25,10,23,4] h = 2

*/