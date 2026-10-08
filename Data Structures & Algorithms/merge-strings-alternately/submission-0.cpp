class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int minWordSize = min(word1.size(), word2.size());
        for(int i = 0; i < minWordSize; i++) {
            res.push_back(word1[i]);
            res.push_back(word2[i]);
        }

        if(word1.size() > minWordSize) {
            res.append(word1.substr(minWordSize, word1.size()));
        } else if (word2.size() > minWordSize) {
            res.append(word2.substr(minWordSize, word2.size()));
        }

        return res;
    }
};