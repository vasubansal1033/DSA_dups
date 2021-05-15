class RandomizedSet {
public:
    /** Initialize your data structure here. */

    // maps element->index in vector
    unordered_map<int, int> m;
    vector<int> v;

    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {

        if(m.find(val)!=m.end())
            return false;

        m[val] = v.size();
        v.push_back(val);
        return true;

    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {

        if(m.find(val)!=m.end()){

            int idx = m[val];
            m.erase(val);
            swap(v[idx], v[v.size()-1]);

            if(idx!=v.size()-1)
                m[v[idx]] = idx;

            v.pop_back();

            return true;

        }else return false;

    }

    /** Get a random element from the set. */
    int getRandom() {

        // srand(time(0));
        return v[(rand()%(v.size()))];

    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
