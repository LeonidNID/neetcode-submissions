class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        bool target1found = false;
        bool target2found = false;
        bool target3found = false;

        for(int i = 0; i < triplets.size(); i++) {
            if(triplets[i][0] > target[0] || 
               triplets[i][1] > target[1] || 
               triplets[i][2] > target[2]) continue;

            if(!target1found && triplets[i][0] == target[0]) target1found = true;
            if(!target2found && triplets[i][1] == target[1]) target2found = true;
            if(!target3found && triplets[i][2] == target[2]) target3found = true;

            if(target1found && target2found && target3found) return true;
        }    

        return false;
    }
};

/*
Given array of triplets [[a1,b1,c1],....[n1,n2,n3]] and a target triplet [t1,t2,t3]
return whether it is possible to form target with a combination of two triplets from our array where each element is the max between an idx in that triplet.

IMPORTANT AFTERWARDS: TARGET DOES NOT HAVE TO BE MADE OF 2 SINGLE TRIPLETS!

Greedy
What information from the past is sufficient to make every future decision

Brute force:
for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
        vector<int> maxLocal = {max(triplets[i][0], triplets[j][0], ..., ...)};
        if(maxLocaK == target) return true;
    }
}
return false;


*/