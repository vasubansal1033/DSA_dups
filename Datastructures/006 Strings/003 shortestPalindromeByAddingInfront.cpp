class Solution {
public:

    int getP(string s){

        vector<int> lps(s.size());
        lps[0] = 0;

        int i(1), j(0);

        while(i<lps.size()){

            if(s[i]==s[j]){
                lps[i] = j+1;
                i++; j++;
            }else{

                if(j==0){
                    lps[i] = 0;
                    i++;
                }else{
                    j = lps[j-1];
                }

            }

        }

        return lps[lps.size()-1];

    }
    string shortestPalindrome(string s) {

        // First we have to find the longest palindrome from starting
        // Then add the reverse of remaining string at the beginning

        // How to find the longest palindrome from starting?
        // We can write out string s = PS, where P is the palindromic part, S is the remaining part
        // Now, s' = ss', where s' means reverse of the string
        // s' = PS(S'P') = PS(S'P) as P is palindrome so P' = P
        // So s' = PSS'P
        // We can get P easily by constructing the lps array. P is the longest prefix and suffix.
        // But it can happen that S can be s.t. that we can get longest string than P which is a prefix and suffix.
        // So we add # to avoid that. s' = PS#S'P

        string s_ = s+'#'+string(s.rbegin(), s.rend());

        int idx = getP(s_);

        string temp = s.substr(idx);
        return string(temp.rbegin(), temp.rend())+s;

    }
};
