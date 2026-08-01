class MyHashMap {
public:
    int m ; 
    vector<list<pair<int,int>>>buckets;
    int getInd(int key){
        return key%m; 
    }
    MyHashMap() {
        m = 15000;
        buckets.resize(m);
    }
    
    void put(int key, int value) {
        int index = getInd(key);

        for(auto it = buckets[index].begin() ; it!= buckets[index].end() ; it++){
            if(it->first == key){
                it->second = value ; 
                return ;
            }
        }
        buckets[index].push_back({key , value});
    }
    
    int get(int key) {
        int index = getInd(key);

        for(auto it = buckets[index].begin() ; it!= buckets[index].end() ; it++){
            if(it->first == key){ 
                return it->second;
            }
        }
        return -1; 
    }
    
    void remove(int key) {
        int index = getInd(key);

        for(auto it = buckets[index].begin() ; it!= buckets[index].end() ; it++){
            if(it->first == key){
                buckets[index].erase(it);
                return ; 
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */