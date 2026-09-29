class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);

        for(int i = 1; i <= n; i++) {
            string binRep = std::format("{:b}\n", i);
            res[i] = count(binRep.begin(), binRep.end(), '1');
        }    

        return res;
    }
};
