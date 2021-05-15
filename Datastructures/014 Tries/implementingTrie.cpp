// Trie node
struct TrieNode{

    bool isWord;
    // TrieNode** next;
    TrieNode* next[26];

    TrieNode(){
        isWord = false;

        // next = new TrieNode*[26];
        for(int i=0; i<26; i++)
            next[i] = NULL;
    }

};

class Trie {
public:
    /** Initialize your data structure here. */

    TrieNode* root;

    Trie() {
        this->root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {

        TrieNode* temp = root;

        for(auto c:word){

            if(!temp->next[c-'a']){
                temp->next[c-'a'] = new TrieNode();
                temp = temp->next[c-'a'];
            }else{
                temp = temp->next[c-'a'];
            }

        }
        temp->isWord = true;

    }

    /** Returns if the word is in the trie. */
    bool search(string word) {

        TrieNode* temp = root;
        for(auto c:word){

            if(!temp->next[c-'a']) return false;
            else temp = temp->next[c-'a'];

        }

        return temp->isWord;

    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {

        TrieNode* temp = root;
        for(auto c:prefix){

            if(!temp->next[c-'a']) return false;
            else temp = temp->next[c-'a'];

        }

        return true;


    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
