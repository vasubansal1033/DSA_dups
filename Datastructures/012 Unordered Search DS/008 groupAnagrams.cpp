class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, int> m;
        string s;
        vector<vector<string>> res;

        for(int i=0; i<strs.size(); i++){

            s = "";
            for(int i=0; i<26; i++)
                s+='0';

            for(int j=0; j<strs[i].size(); j++){
                s[strs[i][j]-'a']++;
            }

            if(m.find(s)==m.end()){
                res.push_back({strs[i]});
                m[s] = res.size()-1;
            }else{
                res[m[s]].push_back(strs[i]);
            }

        }

        return res;

    }
};
