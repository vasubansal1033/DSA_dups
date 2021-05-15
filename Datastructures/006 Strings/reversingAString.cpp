#include<bits/stdc++.h>
using namespace std;

string reverse(string expr){

    for(int i=0,j=expr.length()-1;i<j;i++,j--){
        expr[i]= expr[i]+expr[j];
        expr[j] = expr[i]-expr[j];
        expr[i] = expr[i]-expr[j];
    }
    return expr;

}
int main(){

    string expr;
    getline(cin, expr);
    cout<<reverse(expr)<<endl;

return 0;
}
