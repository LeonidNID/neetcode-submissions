class Solution {
public:
    // O(m) space where m is the number of strings
    // O(m * n) time, m = number of strings, n = longest string
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::array<char, 26>, vector<int>> hash; 
        vector<vector<string>> res;

        for(int i = 0; i < strs.size(); i++) {
            std::array<char, 26> alphabet{};
            for(int j = 0; j < strs[i].size(); j++) {
                alphabet[(strs[i][j]- 'a' + 1)-1]++;
            }
            hash[alphabet].push_back(i); //
        }

        for(auto& [alphabet_key, indices] : hash) {
            vector<string> group;
            for(const auto& num : indices) {
                group.push_back(strs[num]);
            }
            res.push_back(group);
        }

        return res;
    }
};
