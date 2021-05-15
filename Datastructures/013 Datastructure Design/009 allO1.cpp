class AllOne {
public:

    unordered_map<string, pair<int, list<string>::iterator > > cache;
    list<string> dll;

    /** Initialize your data structure here. */
    AllOne() {

    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {

        // key does not exist
        if(cache.find(key)==cache.end()){

            dll.push_back(key);
            list<string>::iterator it = dll.end();
            it--;
            cache[key] = {1, it};

            return;

        }
        // key exists
        // increment the value by one
        // if it is greater than highest value, then modify it

        // new value -> cache[key].first+1 of existing key
        // max value -> cache[dll.front()].first

        if(cache[key].first+1>=cache[dll.front()].first){

            cache[key].first++;
            dll.erase(cache[key].second);
            dll.push_front(key);

            cache[key].second = dll.begin();

            return;

        }

        // the value may increase than its previous element (dont do for first element)
        // key of the previous element -> *(cache[key].second-1)

        if(cache[key].second == dll.begin()){
            cache[key].first++;
            return;
        }

        // if the value of key becomes greater than its previous key, swap them

        auto it = cache[key].second; it--;
        if(cache[key].first+1>cache[*(it)].first){

            string prevKey(*(it));

            cache[key].first++;

            auto temp = cache[key].second;
            cache[key].second = cache[prevKey].second;
            cache[prevKey].second = temp;


            swap(*(cache[key].second), *(cache[prevKey].second));


            return;
        }
        cache[key].first++;
        return;


    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {

        // key doesnot exist
        if(cache.find(key) == cache.end()) return;

        // value is one. remove it
        if(cache[key].first == 1){

            dll.erase(cache[key].second);
            cache.erase(key);
            return;

        }

        // value is less then minimum, move at end
        if(cache[key].first-1<=cache[dll.back()].first){

            cache[key].first--;
            dll.erase(cache[key].second);

            dll.push_back(key);

            auto it = dll.end(); it--;
            cache[key].second = it;

            return;

        }

        // the value may not remain maximum now

        // the value may decrease than its next element (dont do for last element)
        // key of the next element -> *(cache[key].second+1)

        auto it = dll.end(); it--;
        if(cache[key].second == it){

            cache[key].first--;
            return;

        }

        // if the value of key becomes less than its next key, swap them
        it = cache[key].second; it++;
        if(cache[key].first-1<cache[*(it)].first){

            string nextKey(*(it));

            cache[key].first--;

            auto temp = cache[key].second;
            cache[key].second = cache[nextKey].second;
            cache[nextKey].second = temp;

            swap(*(cache[key].second), *(cache[nextKey].second));

            return;
        }

        cache[key].first--;
        return;

    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {

        if(cache.empty())
            return "";

        return dll.front();

    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {

        if(cache.empty())
            return "";
        return dll.back();

    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
