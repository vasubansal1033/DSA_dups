#include<iostream>
using namespace std;

class base{

public:
    virtual void fun(){
        cout<<"Fun of base class"<<endl;
    }
};
class derived:public base{

public:
    void fun(){
        cout<<"Fun of derived class"<<endl;
    }
};
int main(){

    //derived d;
    //d.fun(); // Fun of derived class
    base* b=new derived();
    //b->fun(); // Fun of base class without writing virtual function
    b->fun(); // Fun of derived class with virtual function
return 0;
}
