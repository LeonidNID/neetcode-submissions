class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        
        for(const auto& c : tokens) {
            if(c == "+") {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(a + b);
            } else if(c == "-") {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(b - a);
            } else if(c == "*") {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(a*b);
            } else if(c == "/") {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(b / a);
            } else {
                s.push(stoi(c));
            }
        }

        return s.top();
    }

};

/*
RPN works like so:
Instead of typical 3 * 4, we write 3 4 * (= 12) [ RPN = Stack based]

IMPORTANT:
All expressions are VALID
We get them in a vector like {'1','2','+','3','*','4','-'}


Case 1:
If there are 2 integers before an operand, just evaluate that result
Example 3 4 * (= 12)

Case 2:
If there is only 1 integer before our operation we use Parenthesis
    1 2 + 3 *
    We evaluate 1 2 + as usual so 1 + 2 = 3
    So now we have a valid expression (1 + 2) * 3

APPROACH:
 Use a stack and read vector from the back:


tokens=["4","13","5","/","+"]
(13 / 5) + 4 = 2 + 4 = 6

/       
5   => 
13      2
4       4

*/