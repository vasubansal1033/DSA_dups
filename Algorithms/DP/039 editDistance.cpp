// space optimized solution
class Solution {
public:
    int minDistance(string word1, string word2) {

        vector<vector<int> > dp(2, vector<int>(word2.size()+2));

        // for(int i=word1.size(); i>=0; i--){
        //     dp[i][word2.size()] = word1.size()-i;
        // }
        for(int j=word2.size(); j>=0; j--){
            dp[word1.size()%2][j] = word2.size()-j;
        }

        for(int i=word1.size()-1; i>=0; i--){

            dp[i%2][word2.size()] = word1.size()-i;

            for(int j=word2.size()-1; j>=0; j--){

                if(word1[i]==word2[j])
                    dp[i%2][j] = dp[(i+1)%2][j+1];
                else
                    dp[i%2][j] = min(dp[(i+1)%2][j+1]+1, min(dp[(i+1)%2][j]+1, dp[i%2][j+1]+1));
                    // dp[i][j] = min({dp[i+1][j+1]+1, dp[i+1][j]+1, dp[i][j+1]+1});

            }

        }

        return dp[0][0];

    }
};



class Solution {
public:
    int minDistance(string word1, string word2) {

        vector<vector<int> > dp(word1.size()+1, vector<int>(word2.size()+2));

        for(int i=word1.size(); i>=0; i--){
            dp[i][word2.size()] = word1.size()-i;
        }
        for(int j=word2.size(); j>=0; j--){
            dp[word1.size()][j] = word2.size()-j;
        }

        for(int i=word1.size()-1; i>=0; i--){

            for(int j=word2.size()-1; j>=0; j--){

                if(word1[i]==word2[j])
                    dp[i][j] = dp[i+1][j+1];
                else
                    dp[i][j] = min(dp[i+1][j+1]+1, min(dp[i+1][j]+1, dp[i][j+1]+1));
                    // dp[i][j] = min({dp[i+1][j+1]+1, dp[i+1][j]+1, dp[i][j+1]+1});

            }

        }

        return dp[0][0];

    }
};
