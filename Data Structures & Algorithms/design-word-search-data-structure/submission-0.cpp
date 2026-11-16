struct Node {
    bool valid = false;
    unordered_map<char, Node*> children;
};

class WordDictionary {
public:
    WordDictionary() {
        m_root = new Node();
    }
    
    void addWord(string word) {
        Node* cur = m_root;
        for(const char idx : word) {
            if(!cur->children.contains(idx)) {
                cur->children[idx] = new Node();
            }
            cur = cur->children[idx];
        }
        cur->valid = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, m_root);
    }

    bool dfs(string word, int j, Node* root) {
        Node* cur = root;

        for(int i = j; i < word.size(); i++) {
            char c = word[i];
            if(c == '.') {
                for(const auto [_, child] : cur->children) {
                    if(dfs(word, i+1, child)) {
                        return true;
                    }
                }
                return false;
            } else {
                if(!cur->children.contains(c)) {
                    return false;
                }
                cur = cur->children[c];
            }
        }
        return cur->valid;
    }

private:
    Node* m_root; 
};
