#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > ans(vector<vector<int> > adj){

    int v = adj.size();
    vector<vector<int> > W1(v, vector<int>(v));
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            W1[i][j] = adj[i][j];
        }
    }

    // In kth iteration, we are finding whether to include the kth vertex in the path joining i and j
    for(int k=0; k<v; k++){

        vector<vector<int> > W2(v, vector<int>(v));
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                W2[i][j] =  (W1[i][j])|((W1[i][k])&(W1[k][j])); //min(W1[i][j], W1[i][k]+W1[k][j]);
            }
        }

        // copy the W2 matrix into W1 so that it can be used for calculation again
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                W1[i][j] = W2[i][j];
            }
        }

    }

    return W1;


}
int main(){

	//code
	int t; cin>>t;
	for(int i=0; i<t; i++){

	    int n; cin>>n;
	    vector<vector<int> > adj(n, vector<int>(n));
        cout<<"yes";
	    for(int j=0; j<n; j++){
	        for(int k=0; k<n; k++){
	            cin>>adj[j][k];
	        }
	    }

	    adj = ans(adj);
	    for(int j=0; j<n; j++){
	        for(int k=0; k<n; k++){
	            cout<<adj[j][k]<<" ";
	        }
	    }

	}

return 0;
}
