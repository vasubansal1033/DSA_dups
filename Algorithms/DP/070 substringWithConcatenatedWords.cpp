// Worst case O(n2 * size of a word). Use rabin karp using hash function

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        unordered_map<string, pair<int, int> > dict;
        for(int i=0; i<words.size(); i++){
            dict[words[i]].first = i; // stores index
            dict[words[i]].second++; // stores frequency
        }

        int i(0);
        int sz = words[0].size();
        vector<int> res;

        while(i<s.size()){

            vector<int> visited(words.size(), 0);
            int matches = 0;
            int j = i;
            while(j<s.size() && matches<=words.size()){

                string temp = s.substr(j, sz);
                // if string is in dict and not visited
                if(dict.find(temp)!=dict.end() && visited[dict[temp].first]<dict[temp].second){
                    j+=sz;
                    matches++;
                    visited[dict[temp].first]++;
                }else{
                    break;
                }

            }

            if(matches==words.size()){
                res.push_back(i);
                i++;
            }else{
                i++;
            }

        }

        return res;

    }
};
