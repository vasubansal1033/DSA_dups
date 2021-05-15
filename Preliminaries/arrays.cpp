#include<iostream>
using namespace std;


int main(){

    int A[5] = {2,3,10,9,5};
    for(int i=0;i<5;i++){
        cout<<A[i]<<endl;
    }
    float B[5] = {2.3f, 10.4f, 5}; // use f in end of float to distinguish it from double
    for(float x:B)
        cout<<x<<endl;

    char C[5] = {'A', 66, 'C', 68, 69};
    for(auto x:C)
        cout<<x<<endl;
    for(int x:C)
        cout<<x<<endl;

    for(int x:A)
        cout<<x++<<" ";
    cout<<endl;
    for(int x:A)
        cout<<++x<<" ";
    cout<<endl;
    for(int &x:A)
        cout<<x++<<" ";
    cout<<endl;
    for(int x:A)
        cout<<x<<" ";
return 0;
}
