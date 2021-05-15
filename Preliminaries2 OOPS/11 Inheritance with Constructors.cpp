#include<iostream>
using namespace std;

class base{

public:
    base(){
        cout<<"Default constructor of base class"<<endl;
    }
    base(int x){
        cout<<"Param constructor of base class"<<endl;
    }

};

class derived:public base{

public:
    derived(){
        cout<<"Default constructor of derived class"<<endl;
    }
    derived(int x){
        cout<<"Param constructor of derived class"<<endl;
    }
    derived(int x, int y):base(10){ //--------------//
        cout<<"Param2 constructor of derived class"<<endl;
    }

};

int main(){

    derived d1;
    cout<<"--------------"<<endl;
    derived d2(10);
    cout<<"--------------"<<endl;
    derived d3(10,20);

return 0;
}
