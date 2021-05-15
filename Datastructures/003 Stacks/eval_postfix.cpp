#include<bits/stdc++.h>
using namespace std;

int isDigit(char x){
    if(x>='0' && x<='9')
        return 1;
    else return 0;
}
float eval(string expr){

    stack<int> stk;
    for(int i=0;expr[i];i++){

        if(expr[i]==' '){
            continue;
        }else if(isDigit(expr[i])){
            float num=0;
            while(isDigit(expr[i])){
            num = num*10 + (float)(expr[i]-'0');
            i++;
        }
            i--;
            stk.push(num);
        }else{
            float f1 = stk.top();
            stk.pop();
            float f2 = stk.top();
            stk.pop();
            switch(expr[i])
            {
                    case '+': stk.push(f1+f2); break;
                    case '-': stk.push(f2-f1); break;
                    case '*': stk.push(f2*f1); break;
                    case '/': stk.push(f2/f1); break;
            }
        }

    }
    return stk.top();
}
int main(){

    string expr;
    getline(cin, expr);
    cout<<eval(expr)<<endl;

return 0;
}
