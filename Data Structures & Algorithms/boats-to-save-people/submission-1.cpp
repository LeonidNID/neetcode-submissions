class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int l = 0;
        int r = people.size() - 1;
        int totalBoats = 0; // Need at least 1 boat

        // Sort first
        sort(people.begin(), people.end());

        int totalPeople = 0;
        long long curWeight;
        while(l <= r) {
            if(curWeight + people[r] <= limit && totalPeople < 2) {
                totalPeople++;
                curWeight += people[r];
                r--;
            }
            else if (curWeight + people[l] <= limit && totalPeople < 2)
            {
                totalPeople++;
                curWeight += people[l];
                l++;
            }
            else // Cant take any more people
            {
                totalBoats++;
                totalPeople = 0;
                curWeight = 0;
            }
        }
        //if(curWeight > 0) totalBoats++; // Remaining boat

        return totalBoats;
    }
};

/*
[5,1,4,2] = weight of ith person
infinite boats that can carry "limit" weight
Carry at most 2 people at the same time if wright <= limit
Return min value of boats

GUARANTEED: people[i] <= limit

N <= 1e5

[1,3,2,3,2]
[1,2,2,3,3]
 |       |


*/