#include <bits/stdc++.h>
using namespace std;

long long int dp[25][300005] = {};
long long int nm[300005] = {};

// Complete the decibinaryNumbers function below.
long long int cnt(int d, int s){
    if (d == -1 && s == 0)
        return 1;
    else if (d == -1)
        return 0;
    else if (dp[d][s] == -1){
        dp[d][s] = 0;
        for (int i = 0; i <= 9 && (1 << d)*i <= s; i++)
            dp[d][s] += cnt(d-1, s-((1 << d)*i));
    }
    return dp[d][s];

}

int main(){

    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < 300005; i++) nm[i] = cnt(24, i);
    for (int i = 1; i < 300005; i++) nm[i] += nm[i-1];

    int q, ans;
    cin>>q;

    while (q--){
        long long int x; cin >> x;
        if (x == 1)
            cout << 0 << '\n';
        else{
            int lo = 0, hi = 300004;
            while (lo <= hi){
                int mid = lo+(hi-lo)/2;
                if (nm[mid] >= x){
                    ans = mid;
                    hi = mid-1;
                }
                else
                    lo = mid+1;
            }

            long long int g = x-nm[ans-1], s = ans, val;
            int d;

            for (int i = -1; cnt(i, s) < g; i++) d = i;
            d++;

            while (d >= 0){
                val = 0;
                for (int i = 0; i <= 9; i++){
                    if ((s - (1 << d)*i) >= 0)
                        val += cnt(d-1, s-(1 << d)*i);
                    if (val >= g){
                        cout << i;
                        g -= val-cnt(d-1, s-(1 << d)*i);
                        s -= (1 << d)*i;
                        break;
                    }
                }
                d--;
            }
            cout << '\n';
        }
    }

    return 0;
}
