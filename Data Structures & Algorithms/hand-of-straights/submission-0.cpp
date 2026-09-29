class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> freqMap;
        for(const auto& card : hand) {freqMap[card]++;}

        for(const auto [card, freq] : freqMap) {
            //cout << "Checking card: " << card << "\n";
            if(freq > 0) {

                for(int i = 0; i < groupSize; i++) {
                    if(!freqMap.contains(card+i) || freqMap[card+i] < freq) {
                        //cout << "Returning false at card : " << card+i << " with freq: " << freq << "freq at that card: " << freqMap[card] << "\n";
                        return false;
                    } else {
                        freqMap[card+i] -= freq;
                    }
                }
            }
        }
        return true;
    }
};

/*

1: 0
2: 1
3: 1
4: 1
5: 0

N <= 1e5 O(nlogn) or better

1) Set up freqMap
1: 1
2: 2
3: 2
4: 2
5: 1

2) Iterate through map, start at first
for

*/
