class Solution {
public:
    int hammingWeight(uint32_t n) {
        string s = format("{:b}", n);
        return count(s.begin(), s.end(), '1');
    }
};
