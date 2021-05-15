#include<iostream>
using namespace std;

class base{

public:
    base(){
        cout<<"Constructor of base"<<'\n';
    }
    void display(){
        cout<<"Display of base"<<endl;
    }
};

class derived:public base{

public:

    void display(){
        cout<<"Display of derived"<<endl;
    }

    void display(int x){
        cout<<"Display of derived"<<" "<<x<<endl;
     }
};
int main(){

    derived d;
    d.display(); // Function overloading, if same functions in base and derived class, function
                 // of derived class will override that of base class
    d.display(5);
//    d.base::base(); // cannot call constructor directly
    d.base::display();

return 0;
}
