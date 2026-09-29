class Solution {
public:
    bool checkValidString(string s) {
        stack<int> idxLeft;
        stack<int> idxStars;

        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(') { idxLeft.push(i); }
            else if(s[i] == '*') { idxStars.push(i); }
            else { // Right parenthesis
                if(idxLeft.empty() && idxStars.empty()) return false;
                if(!idxLeft.empty()) idxLeft.pop();
                else idxStars.pop();
            }
        }

        while (!idxLeft.empty() && !idxStars.empty()) {
            if (idxLeft.top() > idxStars.top()) return false;
            idxLeft.pop();
            idxStars.pop();
        }

        return idxLeft.empty();
    }
};
