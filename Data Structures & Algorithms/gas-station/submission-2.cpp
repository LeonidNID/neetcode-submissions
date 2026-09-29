class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalCost = accumulate(cost.begin(), cost.end(), 0);
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        if(totalCost > totalGas) return -1;

        // Because of the invariant above we KNOW that there has to be a valid index!
        int runningDiff = 0;
        int res = 0;
        for(int i = 0; i < (int)gas.size(); i++) {
            runningDiff += gas[i] - cost[i];
            if(runningDiff < 0) {
                res = i + 1;
                runningDiff = 0;
            }
        }

        return res;
    }
};

/*
N <= 1e6 so O(n)

       idx =  0 1 2 3
Input: gas = [1,2,3,4] 
      cost = [2,2,4,1] (to travel from station i to station i+1)
      tank =  4 4 3 5

We have n gasstations and start with an empty tank. From station i to i+1 we pay cost[i+1]. Return idx of first gas station so we can make a circle.
=> Greedily pick ________
=> if tank < cost => return -1

What information from the past is sufficient to make every future decision?

Brute force
Try every index and complete the circle.

gas=[1,2,3,4]
cost=[2,2,4,1]
diff=[-1,0,-1,3]

gas =   [1,2,3]
cost =  [2,3,2]
diff =  [-1,-2,-1]

gas= [1,2,3,4,5]
cost=[3,4,5,1,2]
     [-2,-2,-2,3,3]
     [-2,-4,-6,-3,0]

gas= [5,8,2,8]
cost=[6,5,6,6]
     [-1,3,-4,2]
     [-1,2,-2,0]


gas = [0,1,2]
cost= [0,1,3]
diff= [0,0,-1]
*/