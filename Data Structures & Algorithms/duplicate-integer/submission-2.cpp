class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int,int> nummap;

        for(const auto& num: nums) {
            if(nummap.contains(num)) return true;
            nummap[num]++;
        }
        return false;
    }
};