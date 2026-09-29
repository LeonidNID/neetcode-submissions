class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        // O(n) time / space
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }

        int maxseq = 0;
        for(const auto& num : nums) {
            if(!hash.contains(num-1)) { // identified seqstart
                int tracker = 0;
                int cur = num;
                while(hash.contains(cur)) {
                    cur++;
                    tracker++;
                }
                maxseq = max(maxseq, tracker);
                tracker = 0;
            }
        }
        return maxseq;
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
