// Implementation of LFU Cache in CPP

class LFUCache {
private:
    multimap<int, int> container;
    unordered_map<int, multimap<int,int>::iterator> position;
    unordered_map<int, int> mapper;
    int cap;
    
public:
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(cap==0) return -1;
        if(position.find(key) != position.end())
        {
            auto it = position[key];
            position.erase(key);
            auto pr = *it;
            position[key] = container.insert({pr.first+1,pr.second});
            container.erase(it);
            return mapper[key];
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(cap==0) return;
       if(position.find(key) != position.end())
        {
            auto it = position[key];
            position.erase(key);
            auto pr = *it;
            position[key] = container.insert({pr.first+1,pr.second});
            container.erase(it);
            mapper[key] = value;
            return;
        }
        if(container.size() == cap)
        {
            auto del_KEY = (container.begin())->second;
            container.erase(container.begin());
            mapper.erase(del_KEY);
            position.erase(del_KEY);
        }
        position[key] = container.insert({1,key});
        mapper[key] = value;
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
