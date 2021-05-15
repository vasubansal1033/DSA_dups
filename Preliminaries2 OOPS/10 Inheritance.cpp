#include<iostream>
using namespace std;

class base{

public:
    int x;
public:
    void show(){
        cout<<x<<endl;
    }

};

class derived:public base{

public:
    int y;
public:
    void display(){
        cout<<x<<" "<<y<<endl;
    }

};

int main(){

    base b;
    b.x=20;
    b.show();

    derived d;
    d.x=25;
    d.y=30;
    d.display();

return 0;
}
