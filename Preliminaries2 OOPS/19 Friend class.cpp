#include<iostream>
using namespace std;

class your; // Because your class is declared after friend your command
class my{

private:
    int a;
friend your;
};
class your{

public:
    my object1;

    void fun(){
        object1.a = 10;
        cout<<object1.a;
    }
};
int main(){

your object2;
object2.fun();
return 0;
}
