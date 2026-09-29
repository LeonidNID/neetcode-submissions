class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> mp; // char : (freq, lastIdx)
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]].first++;
            mp[s[i]].second = i;
        }
        
        vector<int> res;
        int totalsize = 0;
        for(int i = 0; i < s.size(); i++) {
            
            int maxIdx = mp[s[i]].second;
            //cout << "maxIdx: " << maxIdx << "\n";
            char targetChar = s[i];
            while(i < maxIdx) {
                if(s[i] == targetChar) {
                    mp[targetChar].first--;
                } else {
                    maxIdx = max(maxIdx, mp[s[i]].second);
                }
                i++;
            }
            res.push_back(maxIdx + 1 - totalsize); // Account for 0-indexed
            totalsize += res.back();
        }

        return res;
    }
};

/*
GIVEN string s like xyxxyzbzbbisl
split into as many substrings as possible 
where every character just shows up in 1 string

RETURN lengths of substrings in descending order
n <= 100
viable n^2 = 1e5 I think
Optimal O(n)!

map : {
x: 3,
y: 2,
z: 2,
b: 3,
i: 1,
s: 1,
l: 1
}

Idea 1: from first character look until last character, include any picked up on the way

xyxxyzbzbbisl
xy: xyxxy (y picked up along the way)

zbzbbisl
zb: zbzbb (b picked along the way)

isl
these are all 1 char
=> 5, 5, 1, 1, 1

Question: How do I do that in O(n)?
- for unique character We need: frequency, last idx in string

start looping for x


*/