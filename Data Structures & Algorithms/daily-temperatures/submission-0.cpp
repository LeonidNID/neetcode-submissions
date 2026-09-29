class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> s; // Monotonic decreasing stack for finding next greater
        // Often better to store indices!

        for(int i = 0; i < n; i++) {
            while(!s.empty() && temperatures[s.top()] < temperatures[i]) { // cond violation
                res[s.top()] = i - s.top(); 
                s.pop();
            }
            s.push(i);
        }

        return res;
    }
};

/*

2
1


Input: vector<int> temperatures of size n
       temperatures[i] = temp on ith day

output: vector<int> res of size n
        res[i] = in res[i] days the temperature will be higher than temp[i]

Idea: Monotonic (decreasing) stack
[30,38,30,36,35,40,28]

38
30

*/

