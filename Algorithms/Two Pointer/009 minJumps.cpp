#include<bits/stdc++.h>
using namespace std;


int ans(vector<int>& v){

    vector<int> maxOnLeft(v.size());
    maxOnLeft[0] = v[0];
    for(int i=1; i<v.size(); i++){
        maxOnLeft[i] = max(maxOnLeft[i-1], v[i-1]);
    }

    int i(v.size()-1);

    i--;
    int steps = 1;
    int jumps = 1;
    while(i>=0){

        if(v[i]==0){
            i--;
            steps++;
        }

        if(v[i]>=steps || maxOnLeft[i]>=steps){
            i--;
            steps++;
        }else{
            steps = 1;
            jumps++;
        }

    }



    return jumps;

}
int main()
 {
	//code
	int t; cin>>t;
	for(int i=0; i<t; i++){

	    int n; cin>>n; vector<int> v(n);
	    for(int j=0; j<n; j++)
            cin>>v[j];
        cout<<ans(v)<<endl;

	}
	return 0;
}
