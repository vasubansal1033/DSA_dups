#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {

    if(prices.size()==0)
        return 0;

    int maxLeft; // stores maximum on left side of array
    int maxi = prices[prices.size()-1]; // maximum so far
    int maxProfit = 0; // stores maximum profit

    // start from second last element, as we cant sell the last element
    for(int i = prices.size()-2; i>=0; i--){

        maxLeft = maxi; // update the maxLeft so far
        maxProfit = max(maxProfit, maxLeft-prices[i]); // get max profit
        maxi = max(maxi, prices[i]); // update maximum

    }

    return maxProfit;
}

int main(){

    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    cout<<maxProfit(v);


return 0;
}
