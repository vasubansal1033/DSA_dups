class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        ios_base::sync_with_stdio(0);
        cin.tie(0);

        int dp[2][nums2.size()+1];
        // memset(dp, 0, sizeof(dp));
        // for(int i=0; i<nums1.size()+1; i++) dp[i][0] = INT_MIN;
        for(int j=0; j<nums2.size()+1; j++) dp[0][j] = INT_MIN;

        dp[0][0] = INT_MIN;
        for(int i=1; i<nums1.size()+1; i++){

            dp[i%2][0] = INT_MIN;
            for(int j=1; j<nums2.size()+1; j++){

                int prod = nums1[i-1]*nums2[j-1];
                if(prod>0){
                    dp[i%2][j] = max(dp[(i-1)%2][j-1]+prod, prod);
                    dp[i%2][j] = max(dp[i%2][j], max(dp[i%2][j-1], dp[(i-1)%2][j]));
                }else{
                    dp[i%2][j] = max(dp[(i-1)%2][j], dp[i%2][j-1]);
                    dp[i%2][j] = max(dp[i%2][j], prod);
                }
            }
        }

        return dp[nums1.size()%2][nums2.size()];
    }
};

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        ios_base::synch_with_stdio(0);
        cin.tie(0);

        int dp[nums1.size()+1][nums2.size()+1];
        for(int i=0; i<nums1.size()+1; i++) dp[i][0] = INT_MIN;
        for(int j=0; j<nums2.size()+1; j++) dp[0][j] = INT_MIN;

        for(int i=1; i<nums1.size()+1; i++){
            for(int j=1; j<nums2.size()+1; j++){

                int prod = nums1[i-1]*nums2[j-1];
                if(prod>0){
                    dp[i][j] = max(dp[i-1][j-1]+prod, prod);
                    dp[i][j] = max(dp[i][j], max(dp[i][j-1], dp[i-1][j]));
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    dp[i][j] = max(dp[i][j], prod);
                }
            }
        }

        return dp[nums1.size()][nums2.size()];
    }
};
