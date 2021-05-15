class Solution {
public:
    bool existUtil(vector<vector<char> >& board, vector<vector<bool> >& visited, string& word, int i, int j, int idx){

        // base conditions
        if(idx==word.size()) return true;
        if(i>=board.size()||i<0||j>=board[0].size()||j<0)
            return false;

        // prune
        if(board[i][j]!=word[idx] || visited[i][j]) return false;

        if(!visited[i][j]){

            if(board[i][j]==word[idx]){

                char c = board[i][j];
                visited[i][j] = true;
                bool b = existUtil(board, visited, word, i+1, j, idx+1)||existUtil(board, visited, word, i-1, j, idx+1)||existUtil(board, visited, word, i, j+1, idx+1)||existUtil(board, visited, word, i, j-1, idx+1);
                visited[i][j] = false;
                return b;
            }else{
                return false;
            }
        }

        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {

        vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false));

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++)
                if(existUtil(board, visited, word, i, j, 0)) return true;
        }

        return false;

    }
};
