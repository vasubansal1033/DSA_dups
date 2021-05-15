#include<bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/find-the-smallest-binary-digit-multiple-of-given-number/
int util(int n){

    queue<int> q;
    q.push(4);

    while(true){

        int fr = q.front(); q.pop();
        if(fr%n==0) return fr;
        q.push(fr*10);
        q.push(fr*10+4);

    }

    return -1;

}
int main(){

    int n; cin>>n;
    int temp = util(n);
    cout<<temp<<" "<<temp/n;

return 0;
}
