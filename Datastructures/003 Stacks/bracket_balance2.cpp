#include<bits/stdc++.h>
using namespace std;

void checkBalance(string expr){

    stack<char> stk;

    for(char x:expr){
        if(x=='(' || x=='[' || x=='{')
            stk.push(x);
        else if(stk.empty()){
            cout<<"Expression is not balanced"<<endl;
            return;
        }
        else if(x ==')'){
            char c = stk.top();
            stk.pop();
            if(c!='('){
                cout<<"Expression is not balanced"<<endl;
                return;
            }
        }else if(x==']'){
            char c = stk.top();
            stk.pop();
            if(c!='['){
                cout<<"Expression is not balanced"<<endl;
                return;
            }
        }else if(x=='}'){
            char c = stk.top();
            stk.pop();
            if(c!='{'){
                cout<<"Expression is not balanced"<<endl;
            }
        }
    }
    if(stk.size()==0){
        cout<<"Expression is balanced"<<endl;
        return;
    }
    cout<<"Expression is not balanced"<<endl;



}
int main(){

    string expr;
    getline(cin, expr);
    checkBalance(expr);

return 0;
}
