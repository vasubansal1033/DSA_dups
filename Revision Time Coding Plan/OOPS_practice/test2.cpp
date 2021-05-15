#include<bits/stdc++.h>
using namespace std;

class base{

private:
    int x;
protected:
    int y;
public:
    int z;
    // have to give this default constructor so that I can call the derived class constructor
    // as it will call the default constructor unless parameters are passed to base class constructor
    base(){
        cout<<"default base class constructor"<<'\n';
    }
    base(int x, int y, int z){ // no need for default constructor, is default values for x,y,z are used int x=0, int y=0....

        cout<<"parametrized base class constructor"<<'\n';
        this->x = x;
        this->y = y;
        this->z = z;
    }
    void show(){
        cout<<x<<" "<<y<<" "<<z<<'\n';
    }

};
class derived:public base{
public:
    derived(){
        cout<<"default derived class constuctor"<<'\n';
    }
    derived(int a, int b){
        cout<<"parametrized derived class constructor"<<'\n';
    }
    derived(int a, int b, int c):base(a, b, c){ // calling base class parametrized constructor
        cout<<"parametrized derived class constructor"<<'\n';
    }
    int a;
    void display(){
        cout<<z<<" "<<a<<'\n';
    }

};


int main(){

//    base b1(1, 2, 3);
//    base b2;
//    cout<<b1.x<<'\n';
//    cout<<b1.y<<'\n';
//    cout<<b1.z<<'\n';
//    b1.show();

//    derived d1;
    derived(1, 2);
//    d1.z = 12; d1.a = 99;
//    d1.display();

return 0;
}
