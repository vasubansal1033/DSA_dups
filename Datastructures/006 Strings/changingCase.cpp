#include<bits/stdc++.h>
using namespace std;

string changeCase(string expr){

    for(int i=0;expr[i];i++){
        if(expr[i]>='A'&&expr[i]<='Z'){
            expr[i]+='a'-'A';
        }else if(expr[i]>='a' && expr[i]<='z'){
            expr[i]+='A'-'a';
        }else continue;
    }
    return expr;
}
int main(){

    string expr;
    getline(cin, expr);
    cout<<changeCase(expr)<<endl;

return 0;
}
