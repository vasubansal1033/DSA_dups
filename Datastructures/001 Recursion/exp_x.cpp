#include<iostream>
using namespace std;

double exp(int x, int n){

    static double p=1, f=1;
    double r;
    if(n==0){
        return 1;
    }
    r = exp(x, n-1);
    p=p*x;
    f=f*n;
    return r + p/f;

}
int main(){

    cout<<exp(1,10);

return 0;
}
