#include<iostream>
using namespace std;

template<class T>
T maxi(T x, T y){
    if(x>y)
        return x;
    else return y;
}
int add(int a, int b){
return a+b;
}
int add(int a, int b, int c){
return a+b+c;
}
int adding(int a, int b, int c=0){
return a+b+c;
}
void swap(int* a, int* b){ // passing by address
    int temp= *a;
    *a=*b;
    *b=temp;
}
void swap2(int &a, int &b){ // passing by reference
    int temp = a;
    a=b;
    b=temp;
}
int main(){

    int a=4, b=8, c=9;
    cout<<add(a,b)<<endl;
    cout<<add(a,b,c)<<endl;
    cout<<adding(a,b)<<endl;
    cout<<adding(a,b,c)<<endl;
    cout<<maxi(5,4)<<endl;
    cout<<maxi(12.59f, 12.60f)<<endl;

    int x=20, y=30;
    cout<<x<<" "<<y<<endl;
    swap(&x,&y);
    cout<<x<<" "<<y<<endl;
    swap2(x,y);
    cout<<x<<" "<<y<<endl;
return 0;
}
