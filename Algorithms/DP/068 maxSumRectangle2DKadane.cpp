// Brute force -> O(n4). Using Kadane O(n3)
#include<bits/stdc++.h>
using namespace std;

int kadane(vector<int>& v){

    int sum = 0;
    int res = INT_MIN;
    for(int i=0; i<v.size(); i++){
        sum = max(v[i], sum+v[i]);
        res = max(sum, res);
    }

    return res;

}
int ans(vector<vector<int> >& mat){


    int res = INT_MIN;
    for(int l=0; l<mat[0].size(); l++){

        vector<int> rowSum(mat.size(), 0);
        for(int r=l; r<mat[0].size(); r++){

            for(int i=0; i<mat.size(); i++)
                rowSum[i] += mat[i][r];

            res = max(res, kadane(rowSum));

        }

    }

    return res;

}
int main()
 {
	//code
	int t; cin>>t;
	for(int i=0; i<t; i++){

	    int r, c; cin>>r>>c;
	    vector<vector<int> > mat(r, vector<int>(c));
	    for(int j=0; j<r; j++){
	        for(int k=0; k<c; k++){
	            cin>>mat[j][k];
	        }
	    }

	    cout<<ans(mat)<<'\n';

	}

	return 0;
}
