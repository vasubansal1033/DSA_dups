#include<bits/stdc++.h>
using namespace std;

void sortStack(stack<int>& stk){

    // base case
    if(stk.empty())
        return;

    int temp = stk.top(); stk.pop();
    sortStack(stk);

    stack<int> tempStk;
    while(!stk.empty() && stk.top()>temp){
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

    sortStack(stk);
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }

return 0;
}
