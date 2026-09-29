class Solution {
public:

    string encode(vector<string>& strs) {
        // Join all together and record at which indices are spaces to be inserted
        // add spaces at the end, delineated by signal word
        //                              
        // "Hello","World,"Yeah" -> "5Hello65World4YeahxX" 
        // -> "Hello World Yeah"
        string ret = "";
        for(string& s : strs) {
            ret += to_string(s.length());
            ret += '#'; // delimeter
            ret += s;
        }
        cout << ret << "\n";
        return ret;
    }

    vector<string> decode(string s) {
        vector<string> ret;
        int i = 0;
        while (i < s.size()) {
            string element = "";
            string numberToDecode = "";
            for(int j = 0; j < s.size(); j++) {
                if(s[i+j] != '#') {
                    numberToDecode += s[i+j];
                } else {
                    break;
                }
            }
            int n = stoi(numberToDecode);

            i+=numberToDecode.size() + 1;

            for(int j = 0; j < n; j++) {
                element += s[i+j];
            }
            i += n;
            ret.push_back(element);
        }
        return ret;
    }
};
