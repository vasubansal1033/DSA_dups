class Solution {
public:
    int expand(string& s, int i, int j){

        int count = 0;
        while(i>=0 && j<s.size()){

            if(s[i]==s[j]){
                i--;
                j++;
                count++;
            }else break;

        }
        return count;

    }
    int countSubstrings(string s) {

        int res = 0;
        for(int i=0; i<s.size(); i++){

            int oddLength = expand(s, i, i);
            int evenLength = expand(s, i, i+1);
            res+=(oddLength+evenLength);

        }
        return res;

    }
};
