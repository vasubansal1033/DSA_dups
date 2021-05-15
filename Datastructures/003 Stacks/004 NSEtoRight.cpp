#include<bits/stdc++.h>
using namespace std;

// 1 3 2 4 8 2 9 6

vector<int> ans(vector<int> v){

    int n = v.size();
    vector<int> ans;
    stack<int> st;

    for(int i=n-1; i>=0; i--){

        if(st.empty())
            ans.push_back(-1);
        else if(st.top()<v[i])
            ans.push_back(st.top());
        else if(st.top()>=v[i]){

            while(!st.empty() && st.top()>=v[i])
                st.pop();
            if(st.empty())
                ans.push_back(-1);
            else ans.push_back(st.top());

        }

        st.push(v[i]);

    }
    reverse(ans.begin(), ans.end());
    return ans;

}
int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){

        int n; cin>>n;
        vector<int> v(n);
        for(int j=0; j<n; j++)
            cin>>v[j];
        v = ans(v);
        for(int j=0; j<n; j++)
            cout<<v[j]<<" ";
        cout<<endl;

    }

}
