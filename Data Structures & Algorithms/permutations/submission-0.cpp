class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> permutation;
        dfs(nums, permutation, 0);
        return res;
    }

    void dfs(vector<int>& nums, vector<int>& p, int i) {
        if(i == nums.size()) { // Complete partitions all have size n
            res.push_back(p);
            return;
        }
        
        vector<int> diff;
        vector<int> v = p;
        sort(v.begin(), v.end());
        set_difference(nums.begin(), nums.end(), v.begin(), v.end(), back_inserter(diff));
        for(const int num : diff) {
            p.push_back(num);
            dfs(nums, p, i+1);
            p.pop_back();
        }
    }
};

/*

permutation: [1]

for(nums without elements from permutation) { // Here 2, 3
    dfs(nums, permutation U element, i+1);
}
=> dfs(nums, [1,2], 2) 
=> dfs(nums, [1,3], 2) 

=> dfs(nums, [1,2,3], 3) // add!
=> dfs(nums, [1,3,2], 3) // add! 

Questions: 
1) What is nums without elements from permutation?
->

2) How do we efficiently get permutation U element=

*/