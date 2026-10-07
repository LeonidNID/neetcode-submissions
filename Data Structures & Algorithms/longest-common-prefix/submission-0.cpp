class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";

        for(int j = 0; j < strs[0].size(); j++) { // letter idx
            char letter = strs[0][j];
            for(int i = 0; i < strs.size(); i++) { // ith string
                if(j >= strs[i].size() || strs[i][j] != letter) return res;
            } 
            res.push_back(strs[0][j]);   
        }

        return res;
    }
};