#include<bits/stdc++.h>
using namespace std;

#define deb(x) cout<< #x <<" "<<x<<endl; // macros
#define loop(st, end) for(int i=st; i<end; i++)

int main(){

    int x(10), y(5);
    deb(x);
    deb(y);

    loop(0, 5){
        deb(x);
    }

    vector<int> vec{1,4 ,2 ,3};
    cout<< accumulate(vec.begin(), vec.begin()+vec.size(), 0);
return 0;
}
