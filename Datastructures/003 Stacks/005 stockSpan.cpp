#include<bits/stdc++.h>
using namespace std;

// find consecutive less than/equal to elements to left for each element
vector<int> ans(vector<int> v){

    int n = v.size();
    vector<int> ans;
    stack<int> st;

    for(int i=0; i<n; i++){

        if(st.empty())
            ans.push_back(-1);
        else if(v[st.top()]>v[i]){
            ans.push_back(st.top());
        }
        else if(v[st.top()]<=v[i]){

            while(!st.empty() && v[st.top()]<=v[i])
                st.pop();
            if(st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top());

        }
        st.push(i);

    }
    for(int i=0; i<n; i++)
        ans[i] = i-ans[i];
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

return 0;
}
