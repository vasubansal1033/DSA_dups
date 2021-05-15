#include<iostream>
using namespace std;

double exp(int x, int n){
    static double s=1;
    if(n==0){
        return s;
    }
    s = 1+x*s/n;
    return exp(x, n-1);

}
int main(){

    cout<<exp(1,10);
return 0;
}
