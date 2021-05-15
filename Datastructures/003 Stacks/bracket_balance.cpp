#include<bits/stdc++.h>
using namespace std;

void checkBalance(string expr){

    stack<char> stk;
    for(char x:expr){
        if(x=='('){
            stk.push(x);
        }else if(x==')'){
            if(stk.size()==0){
                cout<<"Expression is not balanced"<<endl;
                return;
            }
            stk.pop();
        }
    }
    if(stk.size()==0){
        cout<<"Expression is Balanced"<<endl;
    }else{
        cout<<"Expression is not Balanced"<<endl;
    }

}
int main(){

    string expr;
    getline(cin, expr);
    checkBalance(expr);


return 0;
}
