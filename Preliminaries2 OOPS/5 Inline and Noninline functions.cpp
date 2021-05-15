#include<iostream>
using namespace std;


class test{

public:
    void fun1(){
        cout<<"This is an inline function. Machine code is written in main function"<<endl;
    }
    void fun2();
    inline void fun3();
};
void test::fun2(){
    cout<<"This is a non-inline function. Machine code is generated separately."<<endl;
}
void test::fun3(){
    cout<<"This is a inline function. Machine code is generated with main function."<<endl;
}
int main(){

    test t1;
    t1.fun1();
    t1.fun2();
    t1.fun3();

return 0;
}
