#include<iostream>
using namespace std;

class test{

private:
    int a;
    int b;

public:
    static int count;
    test(){
        a = 10;
        b = 10;
        count++;
    }
    static int getCount(){
//        a = 25; # Static member function can only access static data members only.
        return count;
    }
};
int test::count = 0; // Static data members have to be declared outside also
                     // Scope resolution is used so that it can be accessed only by the class and objects.
int main(){

    cout<<test::count<<endl; // static member belongs to a class. It is shared by its objects
    cout<<test::getCount()<<endl;
    test t1;
    test t2;
    cout<<t1.count<<endl;
    cout<<t2.count<<endl;
    cout<<test::count<<endl;

return 0;
}
