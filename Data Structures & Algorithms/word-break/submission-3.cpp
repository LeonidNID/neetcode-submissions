class Solution {
public:
    unordered_map<int, bool> memo;
    bool wordBreak(string s, vector<string>& wordDict) {
        memo[s.length()] = true;
        return dfs(s, wordDict, 0);
    }

    bool dfs(string s, vector<string>& wordDict, int i) {
        if(s.size() == 0) return true;
        if(memo.contains(i)) return memo[i];

        for(const string& word : wordDict) {
            if(s.starts_with(word)) {
                //cout << "Checking string: " << s.substr(word.size(), s.size()) << "\n";
                if(dfs(s.substr(word.size(), s.size()), wordDict, i + word.size())) {
                    memo[i] = true;
                    //cout << "Returning true at i=" << i << "\n";  
                    return true;
                }
            }
        }
        memo[i] = false;
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