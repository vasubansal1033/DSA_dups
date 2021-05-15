class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> m;
        int maxi = 0;

        int i(0), j(0);
        while(j<s.size()){

            m[s[j]]++;


            while(i<=j && m[s[j]]>1){
                m[s[i]]--;
                i++;
            }

            j++;
            maxi = max(maxi, j-i);

        }

        return maxi;

    }
};
