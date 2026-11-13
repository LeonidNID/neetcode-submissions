struct Node {
    bool isValidWord = false;
    unordered_map<char, Node*> children;
};

class PrefixTree {
public:
    PrefixTree() {
        m_root = new Node();
    }
    
    void insert(string word) {
        Node* cur = m_root;
        for(const char c : word) {
            if(!cur->children.contains(c)) {
                cur->children[c] = new Node();
            } 
            cur = cur->children[c];
        }
        cur->isValidWord = true; 
    }
    
    bool search(string word) {
        Node* cur = m_root;
        for(const char c : word) {
            if(!cur->children.contains(c)) {
                return false;
            }
            // Contained
            cur = cur->children[c];
        }
        return cur->isValidWord;    
    }
    
    bool startsWith(string prefix) {
        Node* cur = m_root;
        for(const char c : prefix) {
            if(!cur->children.contains(c)) {
                return false;
            }
            cur = cur->children[c];
        }
        return true;          
    }

private:
    Node* m_root;
};
