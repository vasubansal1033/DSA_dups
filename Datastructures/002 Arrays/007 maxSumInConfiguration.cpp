#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N)
{
//Your code here
    int currSum(0), sumArray(0);
    for(int i=0; i<N; i++){
        currSum+= i*A[i];
        sumArray+=A[i];
    }

    int ans = currSum;
    for(int i=0; i<N-1; i++){
        int temp = currSum - sumArray+N*A[i];
        ans = max(ans, temp);
        currSum = temp;
    }

    return ans;

}

int main(){

    int n; cin>>n;
    int* arr = new int[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<max_sum(arr, n);

return 0;
}
