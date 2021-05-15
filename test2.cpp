#include<bits/stdc++.h>
using namespace std;

int fun(string& s, int start, int last){

    if(start==last){
        return s[start]-'0';
    }

    int mid = start+(last-start)/2;

    int s1 = fun(s, start, mid);
    int s2 = fun(s, mid+1, last);

    int sum = 0;

    string str;
    for(int i=mid+1; i<=last; i++){

        str = "";
        for(int k=mid+1; k<=i; k++)
            str += s[k];

        for(int j=mid; j>=0; j--){
            str = s[j]+str;
            sum += stoi(str);
        }

    }

    return s1+s2+sum;

}
int ans(string& s){
    return fun(s, 0, s.size()-1);
}
int main(){

    string s = "42";
    cout<<ans(s);


return 0;
}
