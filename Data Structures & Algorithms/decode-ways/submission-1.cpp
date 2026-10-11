class Solution {
public:
    unordered_map<int, int> memo;
    int numDecodings(string s) {
        memo[s.size()] = 1;
        return dfs(s, 0);
    }

    int dfs(string s, int i) {
        if(s.size() == 0 || s[i] == '0') return 0;
        if(memo.contains(i)) return memo[i];

        int res = dfs(s, i+1); // We know first char != '0
        if(i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) {
            res += dfs(s, i+2);
        } 

        memo[i] = res;
        return res;
    }
};

/*
0
226



*/
