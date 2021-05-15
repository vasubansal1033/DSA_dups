class TrieNode{
public:
    bool isWord;
    TrieNode* next[26];
    TrieNode(){
        isWord = false;
        for(int i=0; i<26; i++)
            next[i] = nullptr;
    }

};

class Trie{
public:

    TrieNode* root;
    Trie(TrieNode* root){
        this->root = root;
    }
    void insert(string& word){

        TrieNode* curr = this->root;
        for(auto c:word){

            if(curr->next[c-'a'])
                curr = curr->next[c-'a'];
            else{
                curr->next[c-'a'] = new TrieNode();
                curr = curr->next[c-'a'];
            }

        }

        curr->isWord = true;

    }

    bool isConcatenated(string& word, int index, int countConcatenatedWords) {

        if (index == word.size())
            return countConcatenatedWords >= 2;

        TrieNode* curr = this->root;
        for (int i = index; i < word.length(); i++) {

            if (curr->next[word[i]-'a']== nullptr)
                return false;

            curr = curr->next[word[i]-'a'];

            if (curr->isWord)
                if (isConcatenated(word, i + 1, countConcatenatedWords + 1))
                    return true;
        }

        return false;
    }


};
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

        if(words.size()==0) return {};

        TrieNode* root = new TrieNode();
        Trie* dict = new Trie(root);

        for(string word: words){
            dict->insert(word);
        }

        vector<string> res;
        for(string word: words){

            if(dict->isConcatenated(word, 0, 0))
                res.push_back(word);
        }

        return res;
    }
};
