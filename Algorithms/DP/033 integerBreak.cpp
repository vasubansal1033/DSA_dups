class Solution {
public:
    int integerBreak(int n) {

        if(n<=4){
            return n==0?0:n==1?0:n==2?1:n==3?2:4;
        }

        int a = 1; // dp[i-3]
        int b = 2; // dp[i-2]
        int c = 4; // dp[i-1]
        int curr;

        for(int i=5; i<=n; i++){

            curr = max({b*2, a*3, (i-2)*2, (i-3)*3});
            a = b;
            b = c;
            c = curr;

        }

        return curr;

    }
};




class Solution {
public:
    int integerBreak(int n) {

        // Using AM-GM inequality, find an upper bound on the product.
        // Let n/m = x. Then the product will become x^(n/x)
        // The maxima of this expression is x = e = 2.718...
        // But x can be an integer only. So x can be either 2 or 3
        // That means the product will be maximum when the number is a sum of linear combination of 2 and 3.
        // This helped us reduce our solution from O(n^2) to O(n)

        if(n<=4){
            return n==0?0:n==1?0:n==2?1:n==3?2:4;
        }

        vector<int> dp(n+1, 0);
        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 2;
        dp[4] = 4;

        for(int i=5; i<=n; i++){

            dp[i] = max({dp[i-2]*2, dp[i-3]*3, (i-2)*2, (i-3)*3});

        }


        return dp[n];

    }
};



class Solution {
public:
    int integerBreak(int n) {

        vector<int> dp(n+1, 0);
        dp[1] = 0;
        dp[2] = 1;

        for(int i=3; i<=n; i++){

            int temp = 0;
            for(int k=1; k<=i; k++){
                temp = max(dp[i-k]*k, (i-k)*k);
                dp[i] = max(temp, dp[i]);
            }


        }

        for(auto i:dp)
            cout<<i<<" ";

        return dp[n];

    }
};
