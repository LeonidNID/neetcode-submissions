struct Node {
    bool valid = false;
    Node* children[26];

    Node() {
        valid = false;
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class PrefixTree {
public:
    PrefixTree() {
        m_root = new Node();
    }
    
    void insert(string word) {
        Node* cur = m_root;
        for(const char c : word) {
            int idx = c - 'a';
            if(cur->children[idx] == nullptr) {
                cur->children[idx] = new Node();
            }
            cur = cur->children[idx];
        }
        cur->valid = true;
    }
    
    bool search(string word) {
        Node* cur = m_root;
        for(const char c : word) {
            int idx = c - 'a';
            if(cur->children[idx] == nullptr) {
                return false;
            }
            cur = cur->children[idx];
        }
        return cur->valid;
    }
    
    bool startsWith(string prefix) {
        Node* cur = m_root;
        for(const char c : prefix) {
            int idx = c - 'a';
            if(cur->children[idx] == nullptr) {
                return false;
            }
            cur = cur->children[idx];
        }
        return true;
    }

private:
    Node* m_root;
};
