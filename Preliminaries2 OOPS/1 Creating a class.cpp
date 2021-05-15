#include<iostream>
using namespace std;

class rectangle{
    public:
        int len;
        int bread;

    int area(){
        return len*bread;
    }
    int peri(){
        return 2*(len+bread);
    }


};
int main(){

    rectangle r1; // Object created in stack
    r1.len = 10;
    r1.bread = 20;
    cout<<r1.area()<<" "<<r1.peri()<<endl;

    rectangle* ptr = &r1;
    ptr->len = 24;
    cout<<r1.area()<<" "<<r1.peri()<<endl;

    rectangle* r2 = new rectangle(); // Object created in heap
    r2->len = 25;
    r2->bread = 15;
    cout<<r2->area()<<endl;

return 0;
}
