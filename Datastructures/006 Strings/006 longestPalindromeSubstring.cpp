class Solution {
public:
    string longestPalindrome(string s) {

        if(s.size()<1) return "";
        int len = 0;
        int start;
        for(int i=0; i<s.size(); i++){

            int l1 = expand(s, i, i); // oddlength palindrome
            int l2 = expand(s, i, i+1); // even length palindrome

            if(len<max(l1, l2)){
                len = max(l1, l2);
                start = i-((len-1)/2);
            }

        }

        return s.substr(start, len);

    }
    int expand(string& s, int l, int r){

        while(l>=0 && r<s.size()){
            if(s[l]==s[r]){
                l--; r++;
            }else{
                break;
            }
        }

        return (r-l-1);

    }

};
