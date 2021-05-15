#include<iostream>
using namespace std;


class base{

public:
    void fun1(){
        cout<<"ABC"<<endl;
    }
    void fun2(){
        cout<<"ABCD"<<endl;
    }
    void fun3(){
        cout<<"ABCDE"<<endl;
    }

};
class derived:public base{

public:
    void fun4(){
        cout<<"DABC"<<endl;
    }
    void fun5(){
        cout<<"FABC"<<endl;
    }

};
int main(){

    base *ptr; // Declaring base class pointer
    ptr=new derived(); // Storing derived class object using DMA in heap in that pointer

    //derived* ptr2=new base(); This is invalid

    ptr->fun1();
    ptr->fun2();
    ptr->fun3();
    //ptr->fun4(); These cannot be called
    //ptr->fun5();


return 0;
}
