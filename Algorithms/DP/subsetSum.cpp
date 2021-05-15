#include<bits/stdc++.h>
using namespace std;
// Find if a subset of required sum exists in a given array

// recursive solution
bool isPossible(vector<int> v, int sum){

    if(sum==0){
        return true;
    }
    if(v.empty()){
        return false;
    }

    v.pop_back();
    return isPossible(v, sum)||isPossible(v, sum-v[v.size()-1]);

}

/*
// returns the number of subsets with given sum
int count(vector<int> v, int sum, int n){

    if(sum==0){
        return 1;
    }
    if(n<=0){
        return 0;
    }

//    v.pop_back();
    return isPossible(v, sum, n-1)+isPossible(v, sum-v[n-1], n-1);

}

*/

/*
matrix[i][j] tells if the first i elements in v
i.e. from index 0 to i-1 has a subset, whose sum is j or not

Idea: if sum is 0, then true for all subsets. if size is 0, then false for all
Now, say we are at matrix[i][j]
Elements from 0 to i-1 with sum j.
If our current element(v[i-1]) is greater then sum req. then
answer is same as for if elements from 0 to i-2 sum to j
If our current element is smaller then we have
answer for 0 to i-2 elements OR the 0 to i-2 elements sum
to sum minus the current element.



*/
bool isPossible2(vector<int> v, int sum){

    int n = v.size();
    bool matrix[n+1][sum+1];

    // if sum is 0, then true
    for(int i=0; i<=n; i++){
        matrix[i][0] = true;
    }
    // if size of subset is 0, then false
    for(int i=1; i<=sum; i++){
        matrix[0][i] = false;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){

            if(v[i-1]>j){
                matrix[i][j] = matrix[i-1][j];
            }else{
                matrix[i][j] = matrix[i-1][j-v[i-1]]||matrix[i-1][j];
            }


        }
    }
    return matrix[n][sum];

}

int main(){


    int n, sum;
    cin>>n>>sum;
    vector<int> v;
    for(int i=0; i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    cout<<isPossible2(v, sum);


return 0;
}
