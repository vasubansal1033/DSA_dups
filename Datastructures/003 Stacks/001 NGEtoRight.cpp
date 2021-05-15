#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<lli> ans(vector<lli> v){

    lli n = v.size();
    stack<lli> st;

    vector<lli> ans;

    for(lli i=n-1;i>=0; i--){

        if(st.empty()){
            ans.push_back(-1);
        }
        else if(v[i]<st.top()){
            ans.push_back(st.top());
        }
        else if(v[i]>=st.top()){

            while(!st.empty() && st.top()<v[i])
                st.pop();

        if(st.empty())
            ans.push_back(-1);
        else
            ans.push_back(st.top());

        }

        st.push(v[i]);


    }
    reverse(ans.begin(), ans.end());
    return ans;

}

int main(){

    lli t; cin>>t;
    for(lli i=0; i<t; i++){

        lli n; cin>>n;
        vector<lli> v(n);
        for(lli j=0; j<n; j++)
            cin>>v[j];
        vector<lli> ans_v = ans(v);
        for(auto j:ans_v)
            cout<<j<<" ";
        cout<<endl;

    }

return 0;
}
