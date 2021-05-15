typedef pair<int, string> p;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> m;
        for(int i=0; i<words.size(); i++){
            m[words[i]]++;
        }

        auto myComparator = [&](p a, p b){

            if(a.first==b.first)
                return a.second<b.second;
            return a.first>b.first;

        };

        priority_queue<p, vector<p>, decltype(myComparator)> customHeap(myComparator);
        for(auto i:m){
            customHeap.push({i.second, i.first});
            if(customHeap.size()>k)
                customHeap.pop();
        }

        vector<string> v;
        while(!customHeap.empty()){

            v.push_back(customHeap.top().second);
            customHeap.pop();

        }

        reverse(v.begin(), v.end());
        return v;

    }
};
