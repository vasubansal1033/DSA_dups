#include<bits/stdc++.h>
using namespace std;


void reverseStack(stack<int> stk){

    // base case
    if(stk.empty()){
        return;
    }

    int temp = stk.top(); stk.pop();
    reverseStack(stk);

    stack<int> tempStk;
    while(!stk.empty()){
        tempStk.push(stk.top());
        stk.pop();
    }
    stk.push(temp);
    while(!tempStk.empty()){
        stk.push(tempStk.top());
        tempStk.pop();
    }
    return;

}
int main(){

    int n; cin>>n;
    stack<int> stk;
    for(int i=0; i<n; i++){

        int temp; cin>>temp; stk.push(temp);

    }
    reverseStack(stk);
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }

return 0;
}
