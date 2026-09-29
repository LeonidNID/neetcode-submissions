class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res{0};
        
        std::unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++) {
            //cout << "Inserting " << nums[i] << " in s! \n"; 
            s.insert(nums[i]);
        }

        int counter{0};
        for(int num : s) {
            if(!s.contains(num - 1)) {
                int cur = num;
                int len = 1;
                while(s.contains(cur+1)) {
                    cur++;
                    len++;
                }
                res = max(res, len);
            }

        }

        return res;
    }
};

/*
Consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the previous element.
[2,20,4,10,3,4,5]
-> 2,3,4,5

hash: {
2:1
3:1
4:2
5:1
10:1
20:1
}

[0,3,2,5,4,6,1,1]
-> 0,1,2,3,4,5,6 => 7

ANY ORDER! Just has to be 1 over

*/
