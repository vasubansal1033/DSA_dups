#include<bits/stdc++.h>
using namespace std;

void insert_(int& n, int i){
    // set ith bit
    if(n&(1<<i)){
        return;
    }
    else
       n = n | (1<<i);
}
void remove_(int& n, int i){
    // turn off ith bit
    if(!(n&(1<<i))){
        return;
    }
    else
        n = n^(1<<i);

}
void display(int& n){
    // display all set bits
    for(int i=0; i<10; i++){
        if(n&(1<<i))
            cout<<i<<" ";
    }
    cout<<'\n';

}
int main(){

    int n = 54357538;
    display(n);
    insert_(n, 9);
    display(n);
    insert_(n, 2);
    display(n);
    insert_(n, 6);
    display(n);

return 0;
}
