class ListN{
public:
    int key;
    int value;
    int timeuse;
    int timestamp;
    // ListN() = default;
    ListN(int k, int v, int tu, int ts) : key(k), value(v), timeuse(tu), timestamp(ts) {};
    bool operator < (ListN rhs) const {
        if(timeuse == rhs.timeuse){
            return timestamp < rhs.timestamp;
        }
        return timeuse < rhs.timeuse;
    }
};

class LFUCache {
public:
    int size;
    int caps;
    int timestamp;
    unordered_map<int, ListN> hash;
    set<ListN> maps;
    LFUCache(int capacity) {
        timestamp = 0;
        size = 0;
        caps = capacity;

        hash.clear();
        maps.clear(); 
    }
    
    int get(int key) {
        if(caps == 0){
            return -1;
        }
        timestamp++;
        auto it = hash.find(key);
        if(it == hash.end()){
            return -1;
        }
        ListN curnode = it->second;
        maps.erase(curnode);
        curnode.timeuse += 1;
        curnode.timestamp = timestamp;
        maps.insert(curnode);
        it->second = curnode;
        return curnode.value;
    }
    
    void put(int key, int value) {
        if(caps == 0){
            return;
        }
        timestamp++;
        auto it = hash.find(key);
        if(it == hash.end()){
            if(size >= caps){
                auto del_node = maps.begin();
                int del_key = (del_node)->key;
                maps.erase(del_node);
                hash.erase(del_key);
                size--;
            }
            ListN newnode = ListN(key, value, 1, timestamp);
            maps.insert(newnode);
            hash.insert(make_pair(key, newnode));
            size++;
        }else{
            ListN curnode = it->second;
            maps.erase(curnode);
            curnode.value = value;
            curnode.timeuse += 1;
            curnode.timestamp = timestamp;
            maps.insert(curnode);
            it->second = curnode;
        }
    }
};
