class Solution {
public:
    bool isPalindrome(string s) {
        std::erase_if(s, [](unsigned char c) { return !std::isalnum(c); });
        std::ranges::transform(s, s.begin(), [](unsigned char c) {
            return static_cast<char>(std::tolower(c));
        });

        int l = 0;
        int r = static_cast<int>(s.size()) - 1;

        while (l < r) {
            if (s[l] != s[r]) return false;
            ++l;
            --r;
        }
        return true;
    }
};