class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        int total = s.size();
        for(const char c : s) {mp[c]++;}

        vector<pair<char, int>> freqs; // Maybe max heap here
        for(const auto& [c, freq] : mp) {
            if(freq > (s.size() + 1) / 2) return "";
            freqs.push_back({c,freq});
        }

        sort(freqs.begin(), freqs.end(), [](pair<char,int> p1, pair<char,int> p2) 
            {return p1.second > p2.second;});

        string res(s.size(), ' ');
        int i = 0;
        for(auto [c, freq] : freqs) {
            while(freq--) {
                if(i >= s.size()) i = 1;
                res[i] = c;
                i += 2;; // Jump 2 indices
            }
        }

        return res;
    }
};

/*
Need: 
Sort chars by frequency descending
empty data structure per step

N <= 500
Rearrange chars of s so that 2 adjacent are not the same char

---How to know if that is not possible?
axyy
a 1
x 1
y 2

abbccdd

b 3
c 3
d 3
a 1

bcdabcdbcd

bbccdda
bcdabcd


aaabbbb 4 : 3 okay

aaabbbbb 5:3 not ok


if there is one character c where freq[c] > (s.size() / 2) + 1

One 
*/