#include<bits/stdc++.h>
using namespace std;


int main(){

/*
unordered_sets are implemented using hash table.
No duplicates allowed
Insertion, deletion, search takes O(1) time on average. Worst case is O(n)
 compared to log(n) of sets.
Use these, when maintaining order is not required.
If order is required, print/access data in sorted order
or require predecessor/successor of element use set
*/
    int arr[] = {1, 5, 2, 1, 4, 3, 1, 7, 2, 8, 9, 5};
    // find duplicates
    // we can use set here, but order is not necessary
    unordered_set<int > intSet;
    unordered_set<int > duplicates;

    for(int i=0; i< sizeof(arr)/sizeof(arr[0]); i++){
        if(intSet.find(arr[i])==intSet.end()){
            intSet.insert(arr[i]);
        }else{
            duplicates.insert(arr[i]);
        }
    }
    for(auto i: duplicates){
        cout<<i<<" ";
    }





return 0;
}
