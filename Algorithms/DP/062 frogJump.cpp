class Solution {
public:

    bool canCross(vector<int>& stones){

        int N = stones.size();
        vector<vector<bool> > dp(N, vector<bool>(N+1));
        dp[0][1] = true;

        for(int i = 1; i < N; ++i){
            for(int j = 0; j < i; ++j){

                int diff = stones[i] - stones[j];

                // !dp[j][diff] means that if its not possible to jump diff from j then it isn't possible to reach i. so continue

                if(diff < 0 || diff > N || !dp[j][diff])
                    continue;

                dp[i][diff] = true;

                if(diff - 1 >= 0) dp[i][diff - 1] = true;
                if(diff + 1 <= N) dp[i][diff + 1] = true;
                if(i == N - 1) return true;

            }
        }

        return false;
    }
};


class Solution {
public:
    bool canCross(vector<int>& stones) {

        if(stones[1]-stones[0]>1) return false;

        // preliminary check to reduce stupid cases
        for(int i=1; i<stones.size(); i++){

            if(stones[i]-stones[i-1]>i) return false;

        }

        unordered_map<int, unordered_set<int> > lastMove;
        lastMove[0].insert(1);;

        for(int i=1; i<stones.size(); i++){

            for(int j=i-1; j>=0; j--){

                 // If stones[i] is INT_MAX
                unsigned int temp = (unsigned int)(stones[i])-(unsigned int)stones[j]+1;
                if(temp>INT_MAX){
                    continue;
                }

                if(lastMove[j].find(temp)!=lastMove[j].end()){
                    lastMove[i].insert(stones[i]-stones[j]);
                }

                if(lastMove[j].find(stones[i]-stones[j])!=lastMove[j].end() ||
                   lastMove[j].find(stones[i]-stones[j]-1)!=lastMove[j].end()){
                    lastMove[i].insert(stones[i]-stones[j]);
                }

            }

        }

        return lastMove[stones.size()-1].size()==0?false:true;

    }
};
