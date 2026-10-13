class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        // window state

        int runningSum = 0;
        int minElements = INT_MAX;

        for(int r = 0; r < nums.size(); r++) {
            runningSum += nums[r];

            while(runningSum >= target && l <= r) { // 
                minElements = min(minElements, r - l + 1);
            //cout << "Setting minElements = " << minElements << "\n";
                runningSum -= nums[l];
                l++;
            }
        }

        return minElements == INT_MAX ? 0 : minElements;
    }
};

/*
[2,1,5,1] 9

[2,1,5,1,5] 14 > 10
 |       |

[2,1,5,1,5] 12 > 10
   |     |

[2,1,5,1,5] 11 > 10
     |   |
*/