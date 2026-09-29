class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;

        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        // Closest to target -> farthest from target
        sort(cars.rbegin(), cars.rend());

        stack<double> s;

        for (auto [pos, spd] : cars) {
            double eta = static_cast<double>(target - pos) / spd;

            if (s.empty() || eta > s.top()) {
                // Cannot catch fleet ahead -> creates a new fleet
                s.push(eta);
            }
            // eta <= s.top()
            // This car catches the fleet ahead, so don't push it.
        }

        return s.size();
    }
};

/*
Given n cars driwing towards a target t. N cars are described by 2 arrays of size n: position and speed.
N <= 1e6

WE can calculate the ETA of the cars:
double eta = static_cast<double>(position[i] - target) / speed[i]

Use a monotonic stack by eta:
Highest ETA (Slowest car) at the top
Lowest ETA  (fastest car) at the bottom

5.5
4.5
3.0

If A faster car comes, it has to conform to the slower car at the bottom. it becomes a convoy dictated by the slower car.

AND, important, if the new car started behind the slower car


*/