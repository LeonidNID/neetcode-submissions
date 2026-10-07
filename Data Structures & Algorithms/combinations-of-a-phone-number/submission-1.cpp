class Solution {
public:
    unordered_map<char, vector<char>> numMap = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };

    int n;
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        n = digits.size();
        dfs(digits, "", 0);
        return res;
    }

    void dfs(string& digits, string path, int i) {
        if(i == n && path.size() == n) {
            res.push_back(path); // Watch out for double includes
            return;
        }

        for(const auto& c : numMap[digits[i]]) {
            // left
            path.push_back(c);
            dfs(digits, path, i+1);

            //rm
            path.pop_back();

            // No exploration of right,  we only want complete sets of nums
        }
    }
};

/*
Backtracking
between 3 or 4^(digits.size()) combinations;
All of size digits.size()
*/