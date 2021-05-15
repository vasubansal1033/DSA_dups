#include<bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& A, int K) {

    int i(0), j(0);
    int maxLen = INT_MIN;

    // stores number of zeros in curr window
    int countZeros = 0;

    while(j<A.size()){

        if(A[j]==0){
           countZeros++;
        }
        while(countZeros>K){
            if(A[i]==0){
                countZeros--;
            }
            i++;
        }

        maxLen = max(maxLen, j-i+1);
        j++;

    }
    // j-i not j-i+1 as termination is when j==num.size()
    maxLen = max(j-i, maxLen);


    return maxLen;
}
int main(){

    int n; cin>>n; vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    int k; cin>>k;
    cout<<longestOnes(v, k);

return 0;
}
