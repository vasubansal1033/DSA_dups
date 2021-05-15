#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& v, int x){

    int cnt = 0;
    for(int i=0; i<(int)v.size(); i++){
        if(v[i]>x){
            swap(v[i], x);
            cnt++;
        }
        if(i>0){
            if(v[i]<v[i-1]){
                cout<<-1<<'\n';
                return;
            }
        }
    }
    cout<<cnt<<'\n';
    return;

}
int main(){

    int t; cin>>t;

//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    for(int i=0; i<t; i++){

        int n, x; cin>>n>>x;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        solve(v, x);

    }

return 0;
}
