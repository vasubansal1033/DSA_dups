#include<bits/stdc++.h>
using namespace std;


void perm(string expr, int k){
    static int A[10] = {0};
    static char Res[10];

    if(expr[k]=='\0'){
        Res[k]='\0';
        cout<<Res<<endl;
    }else{
        for(int i=0;expr[i];i++){
            if(A[i]==0){
                Res[k]=expr[i];
                A[i]=1;
                perm(expr, k+1);
                A[i]=0;
            }
        }

    }
}
void swap(string expr, int i, int j){
    expr[i]=expr[i]+expr[j];
    expr[j]=expr[i]-expr[j];
    expr[i]=expr[i]-expr[j];
}
void perm2(string expr, int l, int h){

    if(l==h){
        cout<<expr<<endl;
    }else{
        for(int i=l;i<=h;i++){
            swap(expr[i], expr[l]);
            perm2(expr, l+1, h);
            swap(expr[i], expr[l]);
        }
    }
}
int main(){

    string expr;
    getline(cin, expr);
    perm2(expr, 0, expr.length()-1);

return 0;
}
