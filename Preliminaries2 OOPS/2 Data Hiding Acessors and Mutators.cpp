#include<iostream>
using namespace std;


class rectangle{

private:
    int len, bread;
public:
    int get_len(){
        return len;
    }
    void set_len(int length){
        if(length>=0){
            len = length;
        }else{
            len = 0;
            cout<<"Length cannot be negative! Set to 0."<<endl;
        }
    }
    int get_bread(){
        return bread;
    }
    void set_bread(int breadth){
        if(breadth>=0){
            bread = breadth;
        }else{
            bread = 0;
            cout<<"Breadth cannot be negative! Set to 0."<<endl;
        }
    }
    int area(){
        return len*bread;
    }
    int perimeter(){
        return 2*(len+bread);
    }



};
int main(){

    rectangle r1;
    r1.set_len(-20);
    r1.set_bread(-25);

    cout<<r1.area()<<" "<<r1.perimeter()<<endl;
return 0;
}
