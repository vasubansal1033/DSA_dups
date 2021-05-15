// Write your code here
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans(ll* arr, int n){

	ll sum = 0;
	for(int i=0; i<n; i++) sum += arr[i];
	ll avg = sum/n;

	ll b[n];
	b[0] = 0;
	for(int i=1; i<n; i++){
		b[i] = b[i-1]+arr[i-1]-avg;
	}
	sort(b, b+n);
	ll median = b[n/2];
	ll val = 0;
	for(int i=0; i<n; i++){
		val+=abs(b[i]-median);
	}

	return val;


}
int main(){

	int n; cin>>n;
	ll arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];

	cout<<ans(arr, n);


	return 0;
}
