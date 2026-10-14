class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        vector<string> path;
        dfs(s, path, 0, 0);
        return res;
    }

    void dfs(string& s, vector<string>& path, int start, int i) {
        if (i >= s.size()) {
            if (start == s.size()) res.push_back(path);
            return;
        }

        // check if s is palindrome
        auto cur = s.substr(start, i - start + 1);
        if(isPalindrome(cur)) {
            // Add palindromes
            path.push_back(cur);
            dfs(s, path, i+1, i+1);
            path.pop_back();
        }

        dfs(s, path, start, i+1);
    }

    bool isPalindrome(string_view sv) {
        int l = 0;
        int r = sv.size() - 1;

        while(l < r) {
            if(sv[l] != sv[r]) return false;
            --r;
            ++l;
        }
        return true;
    }
};

/*
aba

aabb
  
*/
