class TrieNode{

public:
    bool isWord;
    TrieNode* next[26];

    TrieNode(){
        this->isWord = false;
        for(int i=0; i<26; i++)
            next[i] = nullptr;
    }
};

class wordDictionary{

public:

    TrieNode* root;
    wordDictionary(TrieNode* root){
        this->root = root;
    }
    void insert(string word){

        TrieNode* curr = root;
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
    bool search(string word){

        TrieNode* curr = root;
        for(auto c:word){

            if(curr->next[c-'a'])
                curr = curr->next[c-'a'];
            else return false;

        }

        return curr->isWord;

    }


};

class Solution {
public:
    void fun(vector<vector<char> >& board, unordered_set<string>& restemp, TrieNode* root, string& currString, int i, int j){

        if(root->isWord){
            restemp.insert(currString);

        }
        if(i<0||i>=board.size()||j<0||j>=board[0].size()||board[i][j]=='\n') return;

        for(int k=0; k<26; k++){

            if(root->next[k]){

                if(board[i][j] == (char)('a'+k)){

                    TrieNode* temp = root->next[k];
                    currString += (char)('a'+k);
                    char c = board[i][j];
                    board[i][j] = '\n';

                    fun(board, restemp, temp, currString, i+1, j);
                    fun(board, restemp, temp, currString, i-1, j);
                    fun(board, restemp, temp, currString, i, j+1);
                    fun(board, restemp, temp, currString, i, j-1);

                    board[i][j] = c;
                    currString.pop_back();

                }

            }

        }

    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        TrieNode* root = new TrieNode();
        wordDictionary* dict = new wordDictionary(root);
        for(auto word:words){
            dict->insert(word);
        }

        unordered_set<string> restemp;
        string currString = "";

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++)
                fun(board, restemp, root, currString, i, j);
        }

        vector<string> res(restemp.begin(), restemp.end());

        return res;

    }
};
