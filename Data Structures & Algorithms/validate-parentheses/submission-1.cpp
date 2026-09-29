class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for(int i = 0; i < str.size(); i++) {
                if(str[i] == ')' && !s.empty() && s.top() == '(' || 
                   str[i] == ']' && !s.empty() && s.top() == '[' || 
                   str[i] == '}' && !s.empty() && s.top() == '{') 
                {
                    //cout << "idx i=" << i << "popping \n";
                    s.pop();
                }  else {
                    s.push(str[i]);
                }
        }    

        return s.empty();
    }
};
