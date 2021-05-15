class Solution {
public:
    int dp[2][20][20];
    int calScore(vector<int>& nums, int start, int last, bool isMaximizer){

        if(last<start) return 0;
        if(dp[isMaximizer][start][last]!=-1) return dp[isMaximizer][start][last];

        if(isMaximizer){
            return dp[isMaximizer][start][last] = max(nums[start]+calScore(nums, start+1, last, !isMaximizer), nums[last]+calScore(nums, start, last-1, !isMaximizer));
        }

        return dp[isMaximizer][start][last] = min(-nums[start]+calScore(nums, start+1, last, !isMaximizer), -nums[last]+calScore(nums, start, last-1, !isMaximizer));

    }
    bool PredictTheWinner(vector<int>& nums) {

        // first player can calculate the sum of numbers at even positions and odd positions
        // whichever is greater he can choose that
        if(nums.size()%2==0){
            return true;
        }else{

            // we can use minimax algo
            // player 1 -> maximimzer
            // player 2 -> minimizer
            // score = stones player1 - stones player2

            // if scores are equal then still player 1 wins
            memset(dp, -1, sizeof(dp));

            // for(int i=0; i<2; i++)
            //     for(int j=0; j<nums.size(); j++)
            //         for(int k=0; k<nums.size(); k++)
            //             cout<<dp[i][j][k]<<" ";

            int ans = calScore(nums, 0, nums.size()-1, 1);
            return ans>=0;

        }

    }
};
