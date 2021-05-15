class Solution {
public:
    vector<int> getLPS(string s){

        vector<int> lps(s.size());

        lps[0] = 0;
        int i(1), j(0);
        while(i<s.size()){

            if(s[i]==s[j]){
                lps[i] = j+1;
                i++;
                j++;
            }else{

                if(j==0){
                    lps[i] = 0;
                    i++;
                }else
                    j = lps[j-1];

            }

        }
        return lps;

    }
    int strStr(string haystack, string needle) {

        if(needle.size()==0) return 0;

        int i(0), j(0);
        vector<int> lps = getLPS(needle);

        while(i<haystack.size()){

            if(haystack[i]==needle[j]){
                i++; j++;

                if(j==needle.size())
                    return i-needle.size(); // return beginning index
            }else{

                if(j==0) i++;
                else j = lps[j-1];

            }

        }

        return -1;

    }
};
