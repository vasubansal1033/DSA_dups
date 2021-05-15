#include<bits/stdc++.h>
using namespace std;

/*
// for distinct numbers in O(n)

#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
     int n,k;
     cin>>n;
     int a[n];
     for (int i=0;i<n;i++){
         cin>>a[i];
     }
     int max=a[0],min=a[0];
     for (int i=0;i<n;i++){
         if(a[i]>max)
            max=a[i];
         if(a[i]<min)
            min=a[i];
     }
     int s=max-min+1;
     int h[s]={0};
     for (int i=0;i<n;i++){
         a[i]-=min;
     }

     for (int i=0;i<n;i++){
         h[a[i]]++;
     }
     cin>>k;
     for(int i=0;i<s;i++){
         if(h[i]>=1){
             k--;
         }
         if(k==0){
             cout<<i+min<<endl;
             break;
         }
     }
    }
    return 0;
}

*/

int kthSmallest(vector<int> v, int k){

    priority_queue<int> maxHeap;
    for(int i=0; i<v.size(); i++){

        maxHeap.push(v[i]);
        if(maxHeap.size()>k)
            maxHeap.pop();
    }
    return maxHeap.top();

}
int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){

        int n; cin>>n;
        vector<int> v(n);
        for(int j=0; j<n; j++)
            cin>>v[j];
        int k; cin>>k;
        cout<<kthSmallest(v, k)<<endl;

    }


return 0;
}
