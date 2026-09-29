class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false; // base case
        unordered_map<char, int> mpS1;
        for(int i = 0; i < s1.size(); i++) { mpS1[s1[i]]++; }

        int l = 0;
        unordered_map<char, int> window;// window state

        for(int r = 0; r < s2.size(); r++) {
            char curChar = s2[r];
            window[curChar]++;
            while(window[curChar] > mpS1[curChar]) { // while violates (window characters >)
                window[s2[l]]--;
                l++;
            }
            if(window == mpS1) return true; // if permutation found return true
        }
        return false; 
    }
};
