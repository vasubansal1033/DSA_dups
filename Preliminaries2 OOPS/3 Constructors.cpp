#include<iostream>
using namespace std;

class rectangle{

private:
    int len;
    int bread;

public:
//    rectangle(){
//        len=0;
//        bread=0;
//    }
    rectangle(int l=0, int b=0){
        len=l;
        bread=b;
    }
    rectangle(rectangle &r){
        len=r.len;
        bread=r.bread;
    }
    int getLength(){
        return len;
    }
    void setLength(int length){
        len=length;
    }
    int getBreadth(){
        return bread;
    }
    void setBreadth(int breadth){
        bread=breadth;
    }
    int area(){
        return len*bread;
    }
    int perimeter(){
        return 2*(len+bread);
    }

};
int main(){

    rectangle r1(10);
    cout<<r1.getLength()<<" "<<r1.getBreadth()<<endl;
    r1.setLength(15);
    r1.setBreadth(25);
    cout<<r1.getLength()<<" "<<r1.getBreadth()<<endl;

    rectangle r2(r1);
    cout<<r2.getLength()<<" "<<r2.getBreadth()<<endl;
    cout<<r2.area()<<" "<<r2.perimeter()<<endl;


return 0;
}
