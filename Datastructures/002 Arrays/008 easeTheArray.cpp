#include<bits/stdc++.h>
using namespace std;

vector<int> ans(vector<int>& v){

    for(int i=0; i<v.size()-1; ){

        if(v[i]==v[i+1] && v[i]!=0){
            v[i] = 2*v[i];
            v[i+1] = 0;
            i+=2;
        }else{
            i++;
        }

    }

    int j=0;
    int zerosCount = 0;
    for(int i=0; i<v.size(); i++){

        if(v[i]==0){
            zerosCount++;
        }else{
            v[j] = v[i];
            j++;
        }


    }
    for(int i=v.size()-1; zerosCount>0; i--){
        v[i] = 0;
        zerosCount--;
    }
    return v;

}
int main()
 {
	//code
	int t; cin>>t;
	for(int i=0; i<t; i++){

	    int n; cin>>n; vector<int> v(n);
	    for(int j=0; j<n; j++)
	        cin>>v[j];
	    v = ans(v);
	    for(auto j: v)
	        cout<<j<<" ";
	    cout<<endl;

	}

	return 0;
}
