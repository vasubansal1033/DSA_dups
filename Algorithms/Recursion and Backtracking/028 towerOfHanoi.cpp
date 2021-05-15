#include<bits/stdc++.h>
using namespace std;

// move from a to b using c
void toh(int n, string a, string b, string c){
    if(n<=0) return;

    toh(n-1, a, c, b);
    cout<<"Move from "<<a<<" to "<<c<<'\n';
    toh(n-1, b, a, c);

}
int main(){

    int n; cin>>n;
    toh(n, "A", "B", "C");

return 0;
}
