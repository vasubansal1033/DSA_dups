#include<bits/stdc++.h>
using namespace std;

// recursive solution

bool subsetSum(vector<int> v, int sum, int n){
    if(sum==0)
        return true;
    if(n==0)
        return false;

    if(v[n-1]<=sum){
        return subsetSum(v, sum-v[n-1], n-1)||subsetSum(v, sum, n-1);
    }else{
        return subsetSum(v, sum, n-1);
    }
}
// dp solution
bool dpSolution(vector<int> v, int sum, int n){

    bool arr[sum+1][n+1];
    for(int i=0; i<=n; i++){
        arr[0][i] = true;
    }
    for(int i=1; i<=sum; i++){
        arr[i][0] = false;
    }
    for(int i=1; i<=sum; i++){
        for(int j=1; j<=n; j++){

            if(v[j-1]<=i)
                arr[i][j] = arr[i-v[j-1]][j-1]||arr[i][j-1];
//                arr[i][j] = arr[i-v[j-1]][j-1]+arr[i][j-1]; // make the add sign here for count question
            else
                arr[i][j] = arr[i][j-1];
        }
    }
    return arr[sum][n];

}

// above functions return if subset exists s.t its sum equals given sum
// In equal partition sum, we have to find subset with sum half the sum of array's
// In finding two subsets with given difference, S1-S2 = diff, S1+S2 = arraySum.
// find sum of elements in one subset i.e. S1 = (S2+diff)/2 and use subSet sum problem

// Target sum problem is same as finding two subsets with given difference. Wording is different

bool isPossible(vector<int> v){
    int sum = accumulate(v.begin(), v.end(), 0);
    if(sum%2!=0) return false;
    else{
//        return subsetSum(v, sum/2, v.size()); // recursive
        return dpSolution(v, sum/2, v.size()); // dp solution
    }
}
int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){

        int n; cin>>n;
        vector<int> v(n, 0);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        if(isPossible(v)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

    }


return 0;
}
