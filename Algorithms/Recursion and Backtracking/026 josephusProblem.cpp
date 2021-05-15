#include<bits/stdc++.h>
using namespace std;
// N people are given in a circle. And each person will kill kth person. Starting from 1st person.
// Find the safe index

// [0      |k-1|      n-1]
// Initially k-1 index will be knocked. Now we will start from k numbered index
// [0      |k-1|->    n-1]
// As we are moving in a cycle, we can consider the solution to be of f(n-1, k) starting from kth index
// mod this value with size of array to get an index in array. (k-1+f(n-1, k))%n
// But this answer is calculated for n-1 sized array. therefore ((k-1) + (f(n-1, k)+1))%n = (k-1+f(n-1, k))%n+1

int ans(int n, int k){

    if(n==1) return 1; // 1 based indexing

    return (ans(n-1, k)+k-1)%n+1;

}
int main()
 {
	//code
	int t; cin>>t;
	for(int i=0; i<t; i++){

	    int n, k; cin>>n>>k;
	    cout<<ans(n, k)<<'\n';

	}
	return 0;
}
