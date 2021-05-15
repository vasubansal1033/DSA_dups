#include<iostream>
using namespace std;

class rectangle{

private:
    int length;
    int breadth;

public:
    rectangle(int length, int breadth){
        this->length=length;
        this->breadth=breadth;
    }
    int getLength(){
        return this->length;
    }
    int getBreadth(){
        return this->breadth;
    }

};
int main(){

    rectangle r1(10,20);
    cout<<r1.getLength()<<" "<<r1.getBreadth()<<endl;

return 0;
}
