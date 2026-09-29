class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res(nums.size() - k + 1);
        std::multiset<int> window;
        for(int i = 0; i < k; i++) window.insert(nums[i]);

        for(int i = 0; i < nums.size() - k; ++i) {
            res[i] = *window.rbegin();
            window.erase(window.find(nums[i]));
            window.insert(nums[i+k]);
        }
        res.back() = *window.rbegin();

        return res;
    }
};

/*
[1,2,1,0,4,2,6], k = 3

N <= 1e5 => O(n) ideal

*/