class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        std::unordered_map<char, int> smap;
        std::unordered_map<char, int> tmap;

        for(int i = 0; i < s.length(); i++) {
            smap[s[i]]++;
            tmap[t[i]]++;
        }
        return tmap == smap;
    }
};
