

class LRUCache {
    unordered_map<int, list<pair<int,int>>:: iterator> mp;
    list<pair<int,int> > l;
    int cap;
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            list<pair<int,int> >:: iterator it=mp[key];
            int b=it->first;
            int a=it->second;

            mp.erase(key);
            l.erase(it);
            l.push_front({b, a});
            mp[key]=l.begin();
            return a;

        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            list<pair<int,int> >:: iterator it=mp[key];
            mp.erase(key);
            l.erase(it);
        }
        if(cap==mp.size()){
            int key=l.back().first;

            mp.erase(key);
            l.pop_back();
        }
        l.push_front({key, value});
        mp[key]=l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */