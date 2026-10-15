class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string path = "";
        dfs(path, n*2, 0);
        return res;
    }

    void dfs(string path, int targetLen, int i) {
        if(i >= targetLen) {
            if(isValidParenthesis(path) && i == targetLen) 
                res.push_back(path);
            return;
        }

        path.push_back('(');
        dfs(path, targetLen, i+1);

        path.pop_back();
        path.push_back(')');
        dfs(path, targetLen, i+1);
    }

    bool isValidParenthesis(string& str) {
        stack<char> s;
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == ')' && !s.empty() && s.top() == '(') {
                s.pop();
            }  else {
                s.push(str[i]);
            }
        }    

        return s.empty();
    }
};
