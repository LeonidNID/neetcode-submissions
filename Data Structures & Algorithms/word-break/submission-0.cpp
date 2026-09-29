class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // TODO: Add memoization
        std::unordered_map<string, bool> dp;
        return topDownDP(s, wordDict, dp);
    }

    bool topDownDP(string subString, vector<string>& words, std::unordered_map<string, bool>& dp) {
        if(subString.empty()) return true;
        if(dp.contains(subString)) return dp.at(subString);

        for(const string& word : words) {
            if(subString.starts_with(word)) {
                string res = subString.substr(word.size());
                if(topDownDP(res, words, dp)) {
                    dp[subString] = true;
                    return true;
                }
            }
        }

        dp[subString] = false;
        return false;
    }

};


/*
Given: 
string   s
wordDict 
Can we split up s into words, so that the words are all in dict?

Important:
- can reuse words
- Don't have to use all words

Examples:
neetcode, [neet, code]=> neet, code WORKS
applepenapple, [apple, pen, ape] => apple, pen, apple WORKS
catsincars, [cats, cat, sin, car] => cat, sin, car [S]! DOESNT WORK!

Brute force idea 1: Iterate over string s
Split s into all possible segmentations.
n eetcode
n e etcode
How would I memoize?
=> idk

Brute force idea 2: Iterate over wordDict.
Take string s => can we cut down the prefix of s by some word in wordDict

0) "applepenapple", wordDict = ["apple","pen","ape"]
1) "penapple", wordDict = ["apple","pen","ape"]
2) "apple", wordDict = ["apple","pen","ape"]
3) "", wordDict = ["apple","pen","ape"] => true

What if multiple words match?
=> recurison with call 1 || call 2
*/