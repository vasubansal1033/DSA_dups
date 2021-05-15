// array division question
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

bool ans(vector<lli>& v, int n){

    if(v.size()<=1)
        return false;
    lli sum = accumulate(v.begin(), v.end(), 0);
    if(sum&1){
        return false;
    }
    unordered_map<lli, int> first, second; // O1 time lookup and need of ordering

    first[v[0]]++;
    for(int i=1; i<n; i++)
        second[v[i]]++;

    lli cum_sum = 0;
    for(int i=0; i<n; i++){
        cum_sum+=v[i];
        if(cum_sum==(sum/2)){
            return true;
        }else if(cum_sum<(sum/2)){

            if(second[((sum/2)-cum_sum)]>0)
                return true;

        }else{

            if(first[(cum_sum-(sum/2))]>0)
                return true;
        }
        first[v[i+1]]++;
        second[v[i+1]]--;

    }
    return false;

}
int main(){

    int n; cin>>n;
    vector<lli> v(n+5, 0);
    for(int i=0; i<n; i++)
        cin>>v[i];
    if(ans(v, n))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

return 0;
}
