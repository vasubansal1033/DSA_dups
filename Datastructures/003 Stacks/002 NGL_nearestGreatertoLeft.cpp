#include<bits/stdc++.h>
using namespace std;

vector<int> ans(vector<int> v){

    vector<int> ansV;
    stack<int> st;
    for(int i=0; i<v.size(); i++){

        if(st.empty())
            ansV.push_back(-1);
        else if(st.top()>v[i]){
            ansV.push_back(st.top());
        }else if(st.top()<=v[i]){

            while(!st.empty() && st.top()<=v[i])
                st.pop();

            if(st.empty())
                ansV.push_back(-1);
            else ansV.push_back(st.top());

        }

        st.push(v[i]);

    }
    return ansV;


}
int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){

        int n; cin>>n;
        vector<int> v(n);
        for(int j=0; j<n; j++)
            cin>>v[j];
        vector<int> ansV = ans(v);
        for(auto i:ansV)
            cout<<i<<" ";
        cout<<endl;

    }

}
