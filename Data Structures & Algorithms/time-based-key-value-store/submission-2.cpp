class TimeMap {
private:
    unordered_map<string, vector<string>> strings_map;
    unordered_map<string, vector<int>> times_map;

public:
    TimeMap() = default;
    
    void set(string key, string value, int timestamp) {
        strings_map[key].push_back(value);
        times_map[key].push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        // All the timestamps of set are strictly increasing.
        int l = 0;
        int r = times_map[key].size() - 1;

        // Contains value
        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(times_map[key][mid] > timestamp) {
                r = mid - 1;
            } else if (times_map[key][mid] < timestamp) {
                l = mid + 1;
            }
            else { // if times_map[key]
                return strings_map[key][mid];
            }
        } 

        auto it = lower_bound(times_map[key].begin(), times_map[key].end(), timestamp);

        if (it != times_map[key].begin()) {
            --it;
            int index = it - times_map[key].begin();  // 2
            return strings_map[key][index];
        }

        return "";
    }
};

/*
"TimeMap", 
"set", ["test", "one", 10], 
"set", ["test", "two", 20], 
"set", ["test", "three", 30], 
"get", ["test", 15], 
"get", ["test", 25], 
"get", ["test", 35]]

*/