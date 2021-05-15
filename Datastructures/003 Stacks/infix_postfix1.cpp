#include<bits/stdc++.h>
using namespace std;

int precedence(char x){
    if(x=='^') return 3;
    else if(x=='+'||x=='-') return 1;
    else if(x=='*'||x=='/') return 2;
    else return -1;
}
int isOperand(char c){
    if((c>='a'&&c<='z')||(c>='A'&&c<='Z')) return 1;
    else return 0;
}
string postfix(string expr){

    stack<char> stk;
    string ans;
    for(char x:expr){
        if(isOperand(x)){
            ans.push_back(x);
        }else if(x=='('){
            stk.push(x);
        }else if(x==')'){
            while(stk.top()!='('&&stk.size()!=0){
                ans.push_back(stk.top());
                stk.pop();
            }
            if(stk.top()=='('){
                stk.pop();
            }
        }

        else{
            if(stk.size()==0||(precedence(x)>precedence(stk.top()))){
                stk.push(x);
            }else {
                while(stk.size()!=0 && precedence(x)<=precedence(stk.top())){
                    ans.push_back(stk.top());
                    stk.pop();
                }
                stk.push(x);
            }

        }

    }
    while(stk.size()!=0){
        ans.push_back(stk.top());
        stk.pop();
    }
    return ans;

}
int main(){

    string expr;
    getline(cin, expr);
    cout<<postfix(expr)<<endl;


return 0;
}
