class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> s; // prefer pushing indices
        s.push(0);

        for(int i = 0; i < n; i++) {
            while(!s.empty() && temperatures[i] > temperatures[s.top()]) {
                res[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }

        return res;
    }
};

/*

res = []

30
36
35

38
30

Input: vector<int> temperatures of size n
       temperatures[i] = temp on ith day

output: vector<int> res of size n
        res[i] = in res[i] days the temperature will be higher than temp[i]

Idea: Monotonic (decreasing) stack
[30,38,30,36,35,40,28]

38
30

*/

