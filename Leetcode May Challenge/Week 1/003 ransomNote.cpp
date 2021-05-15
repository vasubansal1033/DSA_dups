class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char, int> hashmap;
        for(int i=0; i<magazine.size(); i++)
            hashmap[magazine[i]]++;

        for(int i=0; i<ransomNote.size(); i++){

            if(hashmap.find(ransomNote[i])!=hashmap.end()){

                hashmap[ransomNote[i]]--;
                if(hashmap[ransomNote[i]]<0)
                    return false;

            }else{
                return false;
            }

        }

        return true;

    }
};
