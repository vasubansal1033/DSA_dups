#include<iostream>
using namespace std;

//void fun(); // declaration not necessary before class
class test{
public:
    int a;
protected:
    int b;
private:
    int c;

friend void fun();
};

void fun(){
    test t;
    t.a = 10;
    t.b = 20;
    t.c = 30;
    cout<<t.a<<" "<<t.b<<" "<<t.c<<endl;
}
int main(){

    fun();

return 0;
}
