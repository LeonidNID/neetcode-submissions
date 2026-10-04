class Solution {
public:
    unordered_set<int> visited;
    unordered_map<int, vector<int>> preMap;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i < prerequisites.size(); i++) {
            pair<int, int> p = {prerequisites[i][0], prerequisites[i][1]};
            preMap[p.first].push_back(p.second);
        }

        for(int i = 0; i < prerequisites.size(); i++) {
            if(!dfs(prerequisites[i][0])) return false;
        }

        return true;
    }

    bool dfs(int course) {
        if(visited.contains(course)) return false; // cycle
        if(preMap[course].empty()) return true; // no preReqs

        visited.insert(course);

        for(int c : preMap[course]) {
            if(!dfs(c)) return false;
        }

        visited.erase(course);
        preMap[course] = {}; // !

        return true;
    }

};

/*

*/
