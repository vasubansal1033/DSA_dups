// memoized and pruned solution
class Solution {
public:
    bool isScrambleUtil(string s1, string s2, unordered_map<string, bool>& m) {

        // base conditions
        if(s1.size()!=s2.size())
            return m[s1+" "+s2] = false;

        if(s1==s2){
            return m[s1+" "+s2] = true;
        }

        if(s1=="" || s2=="")
            return m[s1+" "+s2] = false;

        // pruning condition - check if they have the same character set
        vector<int> v1(26, 0), v2(26, 0);
        for(int i=0; i<s1.size(); i++){
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        if(v1!=v2)
            return m[s1+" "+s2] = false;

        // check if its already calculated
        if(m.find(s1+" "+s2)!=m.end())
            return m[s1+" "+s2];

        for(int k=1; k<s1.size(); k++){

            bool ansA, ansB;

            // case 1 - scrambled
            if(m.find(s1.substr(0, k)+" "+s2.substr(s2.size()-k, k))!=m.end())
                ansA = m[s1.substr(0, k)+" "+s2.substr(s2.size()-k, k)];
            else
                ansA = isScrambleUtil(s1.substr(0, k), s2.substr(s2.size()-k, k), m);

            if(m.find(s1.substr(k, s2.size()-k)+" "+s2.substr(0, s2.size()-k))!=m.end())
                ansB = m[s1.substr(k, s2.size()-k)+" "+s2.substr(0, s2.size()-k)];
            else
                ansB = isScrambleUtil(s1.substr(k, s2.size()-k), s2.substr(0, s2.size()-k), m);

            if(ansA&&ansB)
                return m[s1+" "+s2] = ansA&&ansB;

            // case 2 - not scrambled
            if(m.find(s1.substr(0, k)+" "+s2.substr(0, k))!=m.end())
                ansA = m[s1.substr(0, k)+" "+s2.substr(0, k)];
            else
                ansA = isScrambleUtil(s1.substr(0, k), s2.substr(0, k), m);

            if(m.find(s1.substr(k, s2.size()-k)+" "+s2.substr(k, s2.size()-k))!=m.end())
                ansB = m[s1.substr(k, s2.size()-k)+" "+s2.substr(k, s2.size()-k)];
            else
                ansB = isScrambleUtil(s1.substr(k, s2.size()-k), s2.substr(k, s2.size()-k), m);

            if(ansA&&ansB)
                return m[s1+" "+s2] = ansA&&ansB;

        }

        return m[s1+" "+s2] = false;

    }

    bool isScramble(string s1, string s2){
        unordered_map<string, bool> m;
        return isScrambleUtil(s1, s2, m);
    }
};



class Solution {
public:
    bool isScramble(string s1, string s2) {

        if(s1.size()!=s2.size())
            return false;

        if(s1==s2){
            return true;
        }


        if(s1=="" || s2=="")
            return false;

        for(int k=1; k<s1.size(); k++){

        // if scrambled
        // suppose great and eatgr is split after i=1 and split
        // when k = 2 -> s1.substr(0, k) = gr and s2.substr(n-k, k) = gr. Check if these are scambled
        // and also check if the remaining part that is s1.substr(k, n-k) = eat and s2.substr(0, n-k) = eat are scrambled
        // similarly check for unsplit case

            if(isScramble(s1.substr(0, k), s2.substr(s2.size()-k, k)) &&
               isScramble(s1.substr(k, s2.size()-k), s2.substr(0, s2.size()-k))){
                return true;
            }else if(isScramble(s1.substr(0, k), s2.substr(0, k)) && isScramble(s1.substr(k, s2.size()-k), s2.substr(k, s2.size()-k))){
                return true;
            }

        }

        return false;

    }
};
