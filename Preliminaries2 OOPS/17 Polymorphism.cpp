#include<iostream>
using namespace std;

class car{

public:
    // These functions are called pure virtual function
    virtual void start() = 0; // This statement forces the child classes to implement these
    virtual void stop() = 0;  // so that these functions can be overridden. Note that these dont have code inside
                              // This class is called an abstract class because of this as it is having pure virtual functions.
                              // Cannot create class object of abstract class but pointer can be created
                              // If only pure virtual functions then called interface
};
class innova: public car{

public:

    void start(){
        cout<<"Innova started"<<endl;
    }
    void stop(){
        cout<<"Innova stopped"<<endl;
    }

};
class maruti: public car{

public:

    void start(){
        cout<<"Maruti started"<<endl;
    }
    void stop(){
        cout<<"Maruti stopped"<<endl;
    }

};
int main(){

    car* c = new innova(); // Base class pointer, derived class object
    c->start();

    c = new maruti();
    c->start();
    // Same base class pointer is used to call functions of derived class object.
    // We have achieved polymorphism

return 0;
}
