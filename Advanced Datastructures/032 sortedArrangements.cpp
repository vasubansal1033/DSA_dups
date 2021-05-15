/*

Your are given n and an input array with n numbers.
You have to tell the minimum number of operations needed to pick each element from the input array make a sorted arrangement.
Every insertion and removal is 1 operation.
A sorted arrangement is basically an array that is sorted.
lets understand with example..
let n be 4
and input array be 2 4 1 3
so first we take 2 and insert in the empty sorted arrangement. so 1 operation
then the sorted arrangement is- 2
then we pick 4 and put it in the sorted arrangement.. so we would put after 2 so 1 operation
then the sorted arrangement is- 2 ,4
then we pick 1 and put it in the left so 1 operation..
then the sorted arrangement is- 1,2,4
(now this is important)
now we pick 3 and put we can either remove 1 and 2 put 3 and then again put 2 and 1 back or we can remove 4 , put 3 and again put 4.
obviously the latter takes 3 operations and former takes 5 operations. so we would perform the latter one.
answer is 1+1+1+3=6 operations.

constraints
N<10^5

*/

#include<bits/stdc++.h>
using namespace std;

int* BIT;
int n, maxi;

void update(int i, int val){
    i++; // This for including 0 also. So we are shifting all numbers by 1
    for(; i<=maxi; i+=i&-i){
        BIT[i] += val;
    }
}
int getSum(int i){
    i++;
    int sum = 0;
    for(; i>0; i-=i&-i){
        sum+=BIT[i];
    }
    return sum;
}
int query(int l, int r){
    return getSum(r)-getSum(l-1);
}
int getCount(int num, int i){

    // We can insert a number from left or right
    // for inserting through left, cost will be 2*(number of elements < num)+1
    // for inserting thought right, cost will be 2*(number of elements > num) +1

    int left = getSum(num-1); // getSum(num-1) elements < num
    int right = i-getSum(num); // i numbers will be present current in BIT.
    // out of these getSum(num) are less than or equal to num
    // i-getSum(num) > num.

    return min(left, right)*2+1;

}

int main(){

    cin>>n;
    vector<int> v(n);
    maxi = INT_MIN;
    for(int i=0; i<n; i++){
        cin>>v[i];
        maxi = max(maxi, v[i]);
    }
    // assuming all the elements are in range (1, maxi). Adding 1 before updating, so range (0, maxi)
    BIT = new int[maxi+1];
    memset(BIT, 0, sizeof(int)*(maxi+1));

//    for(int i=0; i<n; i++) update(v[i], 1);

    int cnt = 0;
    for(int i=0; i<v.size(); i++){
        cnt += getCount(v[i], i);
        update(v[i], 1);
    }

    cout<<cnt;

return 0;
}
