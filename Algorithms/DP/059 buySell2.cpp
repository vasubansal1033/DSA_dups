class Solution {
public:

    int maxProfit(vector<int>& prices) {

        vector<int> profit(prices.size());
        profit[0] = 0;

        for(int i=1; i<profit.size(); i++){

            // buy on this day or sell. take maximum
            // actually here we are selling and buying prices[i-1] which effectively cancels
            // transaction for it
            profit[i] = max(profit[i-1], profit[i-1] + prices[i]-prices[i-1]);

            // say we are at i = 3
            // If we buy this then profit[i] = profit[i-1] = 2
            // If we sell this then profit[i] = profit[i-1]+4-3
            // profit[i-1] = 3-1 actually. So net equation becomes 4-3+(3-1) which is 4-1
            // Thus the transaction of buying or selling of three vanishes

        }

        return profit[profit.size()-1];

    }
};


class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int pprofit = 0;

        for(int i=1; i<prices.size(); i++){

            // buy on this day or sell. take maximum
            // actually here we are selling and buying prices[i-1] which effectively cancels
            // transaction for it
            int cprofit = max(pprofit, pprofit + prices[i]-prices[i-1]);

            // say we are at i = 3
            // If we buy this then profit[i] = profit[i-1] = 2
            // If we sell this then profit[i] = profit[i-1]+4-3
            // profit[i-1] = 3-1 actually. So net equation becomes 4-3+(3-1) which is 4-1
            // Thus the transaction of buying or selling of three vanishes
            pprofit = cprofit;
        }

        return pprofit;

    }
};

