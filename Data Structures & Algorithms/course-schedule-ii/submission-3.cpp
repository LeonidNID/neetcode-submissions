class Solution {
public:
    unordered_set<int> visited;
    unordered_map<int, vector<int>> preMap;
    vector<int> res;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i < prerequisites.size(); i++) {
            pair<int, int> p = {prerequisites[i][0], prerequisites[i][1]};
            preMap[p.first].push_back(p.second);
        }

        for(int i = 0; i < prerequisites.size(); i++) {
            if(!dfs(prerequisites[i][0])) return {}; // Cycle
        }

        visited.clear();
        visited.insert(res.begin(), res.end());

        for(int c = 0; c < numCourses; c++) {
            if(!visited.contains(c)) res.push_back(c);
        }

        return res;
    }

    bool dfs(int course) {
        if(visited.contains(course)) return false; // cycle
        if(preMap[course].empty()) {
            if(find(res.begin(), res.end(), course) == res.end())
                res.push_back(course);
            return true; // no preReqs
        }

        visited.insert(course);

        for(int c : preMap[course]) {
            if(!dfs(c)) return false;
        }

        visited.erase(course);
        res.push_back(course);

        preMap[course] = {}; // !

        return true;
    }

};

/*

*/
