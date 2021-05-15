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

class WordDictionary {

public:
    TrieNode* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        this->root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {

        TrieNode* curr = this->root;
        for(auto c:word){

            if(curr->next[c-'a']!=nullptr)
                curr = curr->next[c-'a'];
            else{
                curr->next[c-'a'] = new TrieNode();
                curr = curr->next[c-'a'];
            }

        }

        curr->isWord=true;

    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool searchUtil(string word, TrieNode* node){

        for (int i = 0; word[i] && node; i++) {

            if (word[i] != '.') {
                node = node -> next[word[i] - 'a'];
            } else {

                TrieNode* temp = node;
                for (int j = 0; j < 26; j++) {
                    node = temp -> next[j];
                    if (searchUtil(word.substr(i+1), node)) {
                        return true;
                    }
                }
            }
        }
        return node && node->isWord;

    }
    bool search(string word) {

        TrieNode* curr = root;
        return searchUtil(word, curr);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
