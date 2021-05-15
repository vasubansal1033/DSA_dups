class LRUCache {
public:

    // unordered map from key-> {value, pointer to corresponding node in list}
    unordered_map<int, pair<int, list<int>::iterator > > cache;
    // doubly linked list, least recent item will be placed at head. we can get it in O(1) time
    list<int> dll;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
        dll.clear(); cache.clear();
    }

    int get(int key) {

        if(cache.find(key)==cache.end()) return -1;

        // key exists
        // we have to return the key, and make the corresponding node at head in dll

        auto ptr = cache[key].second;

        dll.erase(ptr); // erase the node
        dll.push_front(key); // make this node at head
        cache[key].second = dll.begin(); // update the pointer in map

        return cache[key].first;
    }

    void put(int key, int value) {

        // case-1 -> key exists, update the value
        if(cache.find(key)!=cache.end()){

            cache[key].first = value;

            auto ptr = cache[key].second;
            dll.erase(ptr);
            dll.push_front(key);

            cache[key].second = dll.begin();

            return;
        }

        // size check
        if(cache.size()<this->capacity){

            dll.push_front(key);
            cache[key] = {value, dll.begin()};

            return;
        }

        // delete the first node and then update
        // dll.front() -> key
        cache.erase(dll.back());
        dll.pop_back();

        dll.push_front(key);
        cache[key] = {value, dll.begin()};


        return;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
