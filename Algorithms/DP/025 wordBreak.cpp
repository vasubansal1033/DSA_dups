class Solution {
public:

    void fun(string& s, unordered_map<string, bool>& m, bool& ans, int start){

        if(start==s.size()){
            ans = true;
            return;
        }

        for(int i=start; i<s.size(); i++){

            if(m.find(s.substr(start, i-start+1))!=m.end()){
                fun(s, m, ans, i+1);
            }

        }

    }
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_map<string, bool> m;
        for(int i=0; i<wordDict.size(); i++)
            m[wordDict[i]] = true;

        bool ans = false;
        fun(s, m, ans, 0);

        return ans;

    }
};


class Solution {
public:
    void wordBreak(string s, vector<string>& wordDict, string& currString, bool& ans, int start){

        // base case
        if(currString == s){
            ans = true;
            return;
        }
        if(currString.size()>s.size())
            return;

        for(int i=0; i<wordDict.size(); i++){
            string temp = currString;
            temp = temp+wordDict[i];
            wordBreak(s, wordDict, temp, ans, start+wordDict[i].size());
        }

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        bool ans = false;
        string currString = "";
        wordBreak(s, wordDict, currString, ans, 0);

        return ans;
    }
};
