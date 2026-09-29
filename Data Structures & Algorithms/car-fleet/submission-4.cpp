class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        for(int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.rbegin(), cars.rend()); // REVERSE Sort by start position;

        // Starting from car closes to target
        int fleets = 1;
        double prevETA = static_cast<double>(target - cars[0].first) / cars[0].second;
        for(int i = 1; i < cars.size(); i++) { 
            double curETA = static_cast<double>(target - cars[i].first) / cars[i].second;
            
            if(curETA > prevETA) {
                prevETA = curETA;
                fleets++;
            }
        }
        
        return fleets;
    }
};

/*

pos_speed = [(0,1), (1,2), (4,2), (7,1)]
*/