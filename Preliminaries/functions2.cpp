#include<iostream>
using namespace std;

int m = 40;

int* fun(int size){ // This is return by address

    int* ptr = new int[size]; // This array is created in heap memory
    for(int i=0;i<size;i++)
        *(ptr+i) = i+1;

    return ptr;
}
int& fun2(int& a){// Return by reference
    cout<<a<<endl;
    return a;
}
void fun3(){
    int a=5;
    static int v = 0; // Static variable exists in memory throughout execution like global variable
                      // but accessible only in the function it is declared in
    a++;
    v++;
    cout<<a<<" "<<v<<endl;
}
int factorial(int n){

    if(n==1){
        return 1;
    }else{
        return n*factorial(n-1);
    }

}
int main(){

    int* ptr = fun(5);
    for(int i=0;i<5;i++)
        cout<<ptr[i]<<" ";
    cout<<"--------"<<endl;
    int a=10;
    cout<<a<<endl;
    fun2(a)=25;
    cout<<a<<endl;

    int m = 10;
    {
        int m = 20;
        cout<<m<<endl;
    }
    cout<<m<<endl;
    cout<<::m<<endl;
    fun3();
    fun3();
    fun3();
    cout<<factorial(10);

return 0;
}
