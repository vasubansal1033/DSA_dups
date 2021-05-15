#include<bits/stdc++.h>
using namespace std;

int main(){

    int cartridges, dollars, recycleReward, perksCost;
    cin>>cartridges>>dollars>>recycleReward>>perksCost;

    int lo = 0, hi = (dollars+(cartridges*recycleReward))/perksCost;
    while(lo<hi){

        int mid = lo+(hi-lo+1)/2;
//        cartridges-mid>=0 && (dollars+(cartridges-mid)*recycleReward)/perksCost>=mid
        int numRecycled = cartridges-mid;
        if(cartridges-mid>=0 && (((dollars+(numRecycled*recycleReward))*1.0/perksCost)>=mid*1.0)){
            lo = mid;
        }else{
            hi = mid-1;
        }

    }

    cout<<lo;

return 0;
}
