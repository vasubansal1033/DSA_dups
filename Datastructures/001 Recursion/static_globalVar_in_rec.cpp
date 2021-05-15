#include<iostream>
using namespace std;

int fun(int x){

    static int n = 0; // creates only one copy
    if(x>0){

        n++;
        return fun(x-1)+n;

    }

}
int main(){

    cout<<fun(11);

return 0;
}
