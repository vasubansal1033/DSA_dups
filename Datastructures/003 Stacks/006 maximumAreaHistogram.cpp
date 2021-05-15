#include<bits/stdc++.h>
using namespace std;

// 6 2 5 4 5 1 6

typedef long long int ulli;
ulli ans(vector<ulli> v){

    int n = v.size();
    vector<ulli> nsl; // nearest smallest to left
    vector<ulli> nsr; // nearest smallest to right

    stack<ulli> st;
    for(int i=0; i<n; i++){

        if(st.empty())
            nsl.push_back(-1); // left ground 0 at index -1
        else if(v[st.top()]<v[i]){
            nsl.push_back(st.top());
        }
        else if(v[st.top()]>=v[i]){

            while(!st.empty() && v[st.top()]>=v[i]){
                st.pop();
            }
            if(st.empty())
                nsl.push_back(-1);
            else
                nsl.push_back(st.top());

        }

        st.push(i);

    }

    while(!st.empty())
        st.pop();

    for(int i=n-1; i>=0; i--){

        if(st.empty())
            nsr.push_back(n); // ground 0 at index n-1+1=n
        else if(v[st.top()]<v[i]){
            nsr.push_back(st.top());
        }
        else if(v[st.top()]>=v[i]){

            while(!st.empty() && v[st.top()]>=v[i])
                st.pop();

            if(st.empty())
                nsr.push_back(n);
            else
                nsr.push_back(st.top());

        }
        st.push(i);
    }
    reverse(nsr.begin(), nsr.end());

    vector<ulli> area;
    for(int i=0; i<n; i++)
        area.push_back((nsr[i]-nsl[i]-1)*v[i]);

    return *max_element(area.begin(), area.end());

}
int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){

        int n; cin>>n; vector<ulli> v(n);
        for(int j=0; j<n; j++)
            cin>>v[j];
        cout<<ans(v)<<endl;


    }

}
