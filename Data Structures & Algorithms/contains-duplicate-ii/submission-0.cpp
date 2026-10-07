class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        vector<pair<int,int>> v(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            v[i] = {nums[i], i};
        }

        sort(v.begin(), v.end());
        for(int i = 0; i < v.size() - 1; i++) {
            //cout << "v[i].first: " << v[i].first << " v[i+1].second: " << v[i+1].first << "\n";
            if(v[i].first == v[i+1].first && 
               abs(v[i].second - v[i+1].second) <= k) {
                return true;
               }
        }
        return false;
    }
};

/*
N <= 1e5
*/