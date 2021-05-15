#include<iostream>
using namespace std;

class parent{

private:
    int a;
protected:
    int b;
public:
    int c;

    void funParent(){
        a=1;
        b=2;
        c=3;
    }

};

class child:virtual private parent{

public:
    void funChild(){
        //a=10; Private member of parent class is not accessible in child class
        b=20; // Now, b and c are private members in child class. Therefore they wont be accessible in grandchild class.
        c=30;
    }
};
class child2:virtual public parent{

public:
    void funChild2(){
        cout<<"Hello world"<<endl;
    }
};
class grandChild:public child,public child2{

public:
//    void funGrandchild(){
//        a=100;
//        b=200;
//        c=300;
//    }
};
int main(){

    grandChild gc;
    gc.funParent();

return 0;
}
