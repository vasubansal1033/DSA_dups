#include<bits/stdc++.h>
using namespace std;

int noOfWords(string expr){
    int count=1;
    for(int i=0;expr[i];i++){
        if(expr[i]==' '&&expr[i-1]!=' ')
            count++;
    }
    return count;
}
int main(){

    string expr;
    getline(cin, expr);
    cout<<noOfWords(expr)<<endl;

return 0;
}
