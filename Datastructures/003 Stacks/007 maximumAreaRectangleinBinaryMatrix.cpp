
#include<bits/stdc++.h>
using namespace std;

// 6 2 5 4 5 1 6

int maximumHisto(vector<int> v){

    int n = v.size();
    vector<int> nsl; // nearest smallest to left
    vector<int> nsr; // nearest smallest to right

    stack<int> st;
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

    vector<int> area;
    for(int i=0; i<n; i++)
        area.push_back((nsr[i]-nsl[i]-1)*v[i]);

    return *max_element(area.begin(), area.end());

}

int ans(vector<vector<int> > v){

    vector<int> histogram(v[0].size(), 0);
    int maxi = INT_MIN;
    for(int i=0; i<v.size(); i++){

        for(int j=0; j<v[0].size(); j++){

            if(v[i][j])
                histogram[j]+=v[i][j];
            else
                histogram[j]=0;
        }
        int a = maximumHisto(histogram);
        if(a>maxi)
            maxi = a;
    }
    return maxi;

}
int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){

        int n, m; cin>>n>>m;
        vector<vector<int> > v(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                cin>>v[i][j];
        }
        cout<< ans(v)<<endl;

    }

}
