class Solution {
public:
    int firstUniqChar(string s) {

        unordered_map<char, int> hashmap;
        int uniqueIndex = 0;
        for(int i=0; i<s.size(); i++){
            hashmap[s[i]]++;
        }
        for(int i=0; i<s.size(); i++){
            if(hashmap[s[i]]==1)
                return i;
        }
        return -1;

    }
};
