class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> smap;
        std::unordered_map<char, int> tmap;

        for(const auto& letter: s) {
            smap[letter]++;
        }

        for(const auto& letter: t) {
            tmap[letter]++;
        }

        for(auto& [key,value] : smap) {
            if(smap[key] != tmap[key]) return false;
        }
        for(auto& [key,value] : tmap) {
            if(tmap[key] != smap[key]) return false;
        }
        return true;
    }
};
