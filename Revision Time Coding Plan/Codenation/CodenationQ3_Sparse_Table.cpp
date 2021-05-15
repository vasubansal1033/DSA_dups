
#include <bits/stdc++.h>  
using namespace std;

typedef long long ll;

// idea taken from https://codeforces.com/blog/entry/80947
// code taken from https://cp-algorithms.com/data_structures/sparse-table.html

vector<int> andQueries(vector<int> numbers, vector<vector<int>>queries) {

    const ll MAXN = 100000;
    const ll K = log2(MAXN);
    int log[MAXN+1];
    log[1] = 0;
    for (int i = 2; i <= MAXN; i++)
        log[i] = log[i/2] + 1;
    int st[MAXN][K + 1];
    const ll N = numbers.size();
    for (int i = 0; i < N; i++)
        st[i][0] = numbers[i];

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = st[i][j-1] & st[i + (1 << (j - 1))][j - 1];

    vector<int> q_ans;
    for(ll i=0;i<queries.size();i++){
        ll l,r,s,t;
        l = queries[i][0];
        r = queries[i][1];
        s = queries[i][2];
        t = queries[i][3];
        l--;r--;
        int ans =0;
        for( ll strt = l;strt + s -1<=r;strt++){

            ll j = log[s];
            ll L = strt;
            ll R = strt + s - 1;
            ll and_val  = (st[L][j] &  st[R - (1 << j) + 1][j]);
            if(and_val >= t)
                ans++;
        }
        q_ans.push_back(ans);
    }

    
    return q_ans;
}

vector<int> brute_force(vector<int> numbers, vector<vector<int>>queries){
     vector<int> q_ans;
    for(ll i=0;i<queries.size();i++){
        ll l,r,s,t;
        l = queries[i][0];
        r = queries[i][1];
        s = queries[i][2];
        t = queries[i][3];
        l--;r--;
        int ans =0;
        for( ll strt = l,end = strt + s -1;end<=r;strt++,end++){
            ll ans_val = (1<<31) -1; 
            for(ll j=strt;j<=end;j++)
                ans_val&=numbers[j];
            if(ans_val >=t)
                ans++;
        }
        q_ans.push_back(ans);
    }
    return q_ans;
}

int main(){
    ll n,q;
    cin>>n;
    vector<int> numbers(n);
    for(ll i=0;i<n;i++)
        cin>>numbers[i];
    ll four;
    cin>>q>>four;
    vector<vector<int>> queries(q,vector<int>(4));
    for(ll i=0;i<q;i++)
        cin>>queries[i][0]>>queries[i][1]>>queries[i][2]>>queries[i][3];

    // comment the above and uncomment the below if you want to run brute force
    // ll n,q;
    // srand(time(0));
    // n = rand()%10000 +1;
    // vector<int> numbers(n);
    // for(ll i=0;i<n;i++)
    //     numbers[i] = rand()%((((ll)1)<<31)-1);
    // q = rand()%500 +1;
    // vector<vector<int>> queries(q,vector<int>(4));
    // for(ll i=0;i<q;i++){
    //     ll l,r,s,t;
    //     l = rand()%n+1;
    //     r = rand()%(n-l)+1;
    //     s = rand()%(r-l+1)+1;
    //     t = rand()%((((ll)1)<<2)-1); // so that sone numbers actually appear
    //     queries[i][0] =l;
    //     queries[i][1] =r;
    //     queries[i][2] =s;
    //     queries[i][3] =t;

    // }

    auto res = andQueries(numbers,queries);
    vector<int> res2(res.size());
    // res2 = brute_force(numbers,queries);
    for(ll i=0;i<res.size();i++)
        cout<<res[i]<<" "<<res2[i]<<endl;
}