class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> sorted = strs;
        vector<vector<string>> output;
        for (auto& s : sorted) {
            std::sort(s.begin(), s.end());
        }
        std::unordered_map<string, vector<int>> hash;
        for(int i = 0; i < sorted.size(); i++) {
            if(!hash.contains(sorted[i])) {
                hash[sorted[i]] = vector{i};
            } else {
                hash[sorted[i]].push_back(i);
            }
        }

        for (const auto& [key, value] : hash) {
            std::vector<string> group;
            for(const auto& idx : value) {
                group.push_back(strs[idx]);
            }
            output.push_back(group);
        }
        return output;
    }
};
