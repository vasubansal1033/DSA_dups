class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    unordered_map<int, vector<int> > m;
    vector<int> v;

    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {

        // flag for checking the element was already present or not
        int flag = m[val].size()!=0?0:1;
        m[val].push_back(v.size());
        v.push_back(val);

        return flag;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {

        // check if its not present in map
        if(m.find(val)==m.end())
            return false;

        // if present, get the index of last occurence from vector of indices
        int idx = m[val][m[val].size()-1];
        m[val].pop_back(); // remove it

        // if vector size is 0, erase it
        if(m[val].size()==0)
            m.erase(val);

        // swap with last element in main vector for easy removal
        swap(v[idx], v[v.size()-1]);
        v.pop_back();

        // now v[idx] has last element
        // m[v[idx]] the vector for last element
        // Since we modified the last occurence of this element, it must at end of this vector
        if(idx!=v.size()){
            m[v[idx]][m[v[idx]].size()-1] = idx;
            // sort the vector, since all the occurences are added in occurence of their insertion
            sort(m[v[idx]].begin(), m[v[idx]].end());
        }


        return true;

    }

    /** Get a random element from the collection. */
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
