class LRUCache {
public:
    LRUCache(int capacity) { m_capacity = capacity; }
    
    int get(int key) {
        if(!m_cache.contains(key)) return -1;
        m_order.erase(m_cache[key].second); // erase from list via iter
        m_order.push_back(key); // push back
        m_cache[key].second = --m_order.end(); // set cache element
        return m_cache[key].first;
    }
    
    void put(int key, int value) {
        if(m_cache.contains(key)) {
            m_order.erase(m_cache[key].second);
        } else if (m_cache.size() == m_capacity) { // evict LRU
            int lru = m_order.front();
            m_order.pop_front();
            m_cache.erase(lru); // erase from unordered_map via int key
        }
        m_order.push_back(key); // back element is MRU
        m_cache[key] = {value, --m_order.end()};
    }

private:
    unordered_map<int, pair<int, list<int>::iterator>> m_cache;
    list<int> m_order;
    int m_capacity;
};
