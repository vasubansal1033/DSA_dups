#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices){

    if(prices.size()<2)
        return 0;

    int n = prices.size();

    // maxRight will store maximum in the right subarray for ith element
    vector<int> maxRight(n);
    maxRight[n-1] = prices[n-1];
    for(int i=n-2; i>=0; i--)
        maxRight[i] = max(prices[i], maxRight[i+1]);

    // store max-profit for first transaction
    int profit1 = max(prices[1]-prices[0], 0);
    // will store profit for second transaction
    int profit2, result, netProfit;
    result = profit1;
    int mini = min(prices[0], prices[1]);

    for(int i=2; i<n; i++){

        // cannot sell after last day, profit will be zero in that case
        if(i<n-2)
            profit2 = max(0, maxRight[i+1]-prices[i]);
        else
            profit2 = 0;
        netProfit = profit1+profit2;
        result = max(result, netProfit);

        // update profit1 for next iteration
        profit1 = max(profit1, prices[i]-mini);
        // update mini for next iteration
        mini = min(mini, prices[i]);

    }

    // could be possible that one transaction results in more profit
    return max(result, profit1);

}
int main(){

    int n; cin>>n; vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    cout<<maxProfit(v);

return 0;
}
