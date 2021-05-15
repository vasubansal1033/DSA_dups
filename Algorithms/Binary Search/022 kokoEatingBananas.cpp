#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

// function that calculates koko's time based on its speed
lli kokoTime(vector<lli>& piles, lli k){

    lli count_ = 0;
    for(lli i=0; i<piles.size(); i++){

        count_+= ceil(1.0*piles[i]/k);

    }

    return count_;

}
lli minEatingSpeed(vector<lli>& piles, lli H) {

    lli lo = 1;
    lli hi = *max_element(piles.begin(), piles.end());

    while(lo<hi){

        lli mid = lo+(hi-lo)/2;
//        cout<<lo<<" "<<mid<<" "<<hi<<endl;

        if(kokoTime(piles, mid)<=H){
            hi = mid;
        }else{
            lo = mid+1;
        }

    }

    return lo;

}

int main(){

//    lli n,H; cin>>n>>H;
//    vector<lli> v(n);
//
//    for(lli i=0; i<n; i++)
//        cin>>v[i];

    lli n = 5; lli H = 823855818;
    vector<lli> v = {332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184};
    cout<<minEatingSpeed(v, H)<<endl;

}
