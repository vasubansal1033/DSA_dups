class Solution {
public:


    int numJewelsInStones(string J, string S) {

        unordered_map<char, int> hashmap;

        for(int i=0; i<J.size(); i++)
            hashmap[J[i]]++;

        int count = 0;

        for(int i=0; i<S.size(); i++){

            if(hashmap.find(S[i])!=hashmap.end())
                count++;

        }

        return count;

    }
};
