class Solution {
public:
    vector<int> countBits(int num) {

        if(num==0)
            return {0};
        if(num==1)
            return {0, 1};

        vector<int> dp(num+1, 0);
        dp[1] = 1;

        int two_power = 2;
        int i;
        while(1){

            for(i=two_power; i<=two_power*2-1; i++){

                if(i>num)
                    break;

                dp[i] = dp[i-two_power]+1;

            }
            if(i>num)
                break;

            two_power*=2;

        }

        return dp;

    }
};
