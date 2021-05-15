class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> map_t;
        for(auto c:t)
            map_t[c]++;

        int start, len=INT_MAX, matches = 0;
        unordered_map<char, int> map_window;
        for(int i=0, j=0; j<s.size(); j++){

            if(map_t.find(s[j])!=map_t.end()){
                map_window[s[j]]++;
                if(map_window[s[j]]<=map_t[s[j]]) matches++;
            }

            if(matches>=t.size()){

                while(map_t.find(s[i])==map_t.end() || map_window[s[i]]>map_t[s[i]]){
                    map_window[s[i]]--;
                    i++;
                }
                if(j-i+1<len){
                    start = i;
                    len = j-i+1;
                }

                map_window[s[i]]--;
                i++;
                matches--;
            }

        }

        return len==INT_MAX?"":s.substr(start, len);

    }
};



class Solution {
public:
    // return true if m2 subset of m1
    bool isContain(unordered_map<char, int>& m1, unordered_map<char, int>& m2){

        for(auto it = m2.begin(); it!=m2.end(); it++){

            char c = it->first; int freq = it->second;
            if(m1.find(c)!=m1.end() && m1[c]>=freq) continue;
            else return false;
        }

        return true;

    }
    string minWindow(string s, string t) {

        if(s.size()<t.size()) return "";
        if(s.size()==t.size()){

            unordered_map<char, int> map_s, map_t;
            for(int i=0; i<s.size(); i++){
                map_s[s[i]]++;
                map_t[t[i]]++;
            }
            if(isContain(map_s, map_t)) return s;
            else return "";

        }
        unordered_map<char, int> map_t;

        for(int i=0; i<t.size(); i++)
            map_t[t[i]]++;

        int i(0), j(0);

        unordered_map<char, int> map_s;
        int len = INT_MAX;
        int start, last;
        while(i<=j && j<s.size()){

            while(j<s.size() && !isContain(map_s, map_t)){
                map_s[s[j]]++;
                j++;
            }

            while(i<j && isContain(map_s, map_t)){

                map_s[s[i]]--;
                if(map_s[s[i]]==0) map_s.erase(s[i]);
                i++;
            }

            if(j-i+1<len){
                len = j-i+1;
                start = i-1;
                last = j;
            }


        }

        if(len>s.size()) return "";
        return s.substr(start, len);

    }
};
