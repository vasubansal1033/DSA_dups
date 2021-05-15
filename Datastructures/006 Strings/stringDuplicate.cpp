#include<bits/stdc++.h>
using namespace std;

void findDuplicate(string expr){

    long int H=0, x;
    for(char x_:expr){
        x=1;
        x=x<<(x_-'a');
        if(H&x){
            cout<<x_<<"  is duplicated in string."<<endl;
        }else{
            H = H|x;
        }
    }
}
int main(){

    string expr;
    getline(cin, expr);
    findDuplicate(expr);

return 0;
}
