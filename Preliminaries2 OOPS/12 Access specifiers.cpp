#include<iostream>
using namespace std;

class base{

private:
    int a;
protected:
    int b;
public:
    int c;

    void funbase(){
        a=10; // In the base class all three types are accessible
        b=20;
        c=30;
    }
};
class derived:public base{

public:
    void funderived(){
//        a=1; // In the derived class, private members are not accessible
        b=2;
        c=3;
    }

};
int main(){

    derived d;
//    d.a=100; // On an object, only public members are accessible
//    d.b=200;
    d.c=300;
    cout<<d.c<<endl;

return 0;
}
