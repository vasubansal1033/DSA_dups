#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
bool isCollinear[1<<16]; // stores if all points represented by mask i, are collinear or not
pair <int, int> rec[1<<16]; // rec[i].first stores minimum possible moves to remove all points for mask i.
int x[16], y[16], n;

pair <int, int> f(int mask){

    // pair int values get initialized by 0
    // memo return
    if (rec[mask].first > 0){
        return rec[mask];
    }
    pair <int, int> &ret = rec[mask];

    // if this mask is already collinear, we can remove all points in one move. Also number of ways will be 1
    if (isCollinear[mask]){
        return ret = make_pair(1, 1);
    }

    int left = mask & (mask - 1);
    int lowbit = mask ^ left; // only the rightmost/least significant bit in mask is on
    ret = f(mask ^ lowbit); // consider removing only the left most point in this mask, recurring for leftover mask

    for (int k = left; k > 0; k = (k - 1) & left){

        if (isCollinear[k|lowbit]){

            pair <int, int> tmp = f(mask ^ (k | lowbit));

            if (tmp.first < ret.first){
                ret = tmp;
            } else if (tmp.first == ret.first){
                ret.second = (ret.second + tmp.second) % MOD;
            }
        }
    }
    ++ret.first;
    return ret;
}
// this function checks if the points represented by the mask are collinear or not
// Consider the first two points. Then checks if other points also lie on this or not
bool check(int mask){

    int i = 0;

    while(!(mask & (1 << i)) && i < n) i++;
    int x0 = x[i], y0 = y[i];
    i++;

    while(!(mask & (1 << i)) && i < n) i++;
    int x1 = x[i], y1 = y[i];
    ++i;

    while (i < n){
        if (mask & (1 << i)){
            if ( (x1 - x0) * (y[i] - y0) != (x[i] - x0) * (y1 - y0)){
                return false;
            }
        }
        i++;
    }

    return true;
}
// for all possible groups, precompute which represent the groups having all points collinear
void init(){

    for (int i = 0; i < (1 << n); ++i){

        rec[i] = make_pair(0,0);
        int j = i & (i - 1); // turnoff the right most bit of i
        if (j & (j - 1)) // j&(j-1) has turned on rightmost bit of j. So rightmost two bits of i are turned off
            isCollinear[i] = check(i);
        else // reach here when the mask i has only two bits set. After turning off two rightmost bits, we will have 0 in this case
            isCollinear[i] = true; // two points are always collinear

    }
}
int main(){

    int t; cin>>t;
    while (t--){
        cin>>n;
        for (int i = 0; i < n; ++i){
            cin>>x[i]>>y[i];
        }
        init();
        pair<int, int> temp = f((1<<n)-1);

        int ans1 = temp.first;
        long long ans2 = temp.second;

        for (int i = 2; i <= ans1; ++i){
            ans2 = ans2 * i % MOD;
        }
        cout<<ans1<<" "<<(int)(ans2)<<'\n';
    }

    return 0;
}
