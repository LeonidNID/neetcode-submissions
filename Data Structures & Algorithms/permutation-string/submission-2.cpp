class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false; // base case
        unordered_map<char, int> mpS1;
        for(int i = 0; i < s1.size(); i++) { mpS1[s1[i]]++;}

        int l = 0;
        unordered_map<char, int> window;

        for(int r = 0; r < s2.size(); r++) {
            char cur = s2[r];
            window[cur]++;

            while(window[cur] > mpS1[cur]) {
                window[s2[l]]--;
                l++;
            }

            if(mpS1 == window) return true;
        }

        return false; 
    }
};
