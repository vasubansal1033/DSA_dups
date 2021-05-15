class TimeMap {
public:
    /** Initialize your data structure here. */

    // unordered_map from string to vector of pairs(as multiple keys are possible)
    unordered_map<string, vector<pair<string, int> > > m;
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        m[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp) {

        // vector<pair<string, int> > v = m[key];

        // fffftttt
        int lo(0), hi(m[key].size()-1);
        while(lo<hi){
            int mid = lo+(hi-lo+1)/2;

            if(m[key][mid].second>timestamp)
                hi = mid-1;
            else
                lo = mid;

        }

        if(m[key][lo].second<=timestamp)
            return m[key][lo].first;
        else
            return "";


    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
