#include<iostream>
using namespace std;


class complex_{

public:
    int real;
    int comp;

public:
    complex_(int real=0, int comp=0){
        this->real=real;
        this->comp=comp;
    }
    complex_ add(complex_ c){
        complex_ temp;
        temp.real=this->real+c.real;
        temp.comp=this->comp+c.comp;

        return temp;

    }
    complex_ operator+(complex_ c){
        complex_ temp;
        temp.real=this->real+c.real;
        temp.comp=this->comp+c.comp;

        return temp;
    }

};
int main(){

    complex_ c1(5,10);
    complex_ c2(10,20);

    complex_ c3;
    c3=c1.add(c2);
    cout<<c3.real<<" "<<c3.comp<<endl;
    c3=c2+c3;
    cout<<c3.real<<" "<<c3.comp<<endl;

return 0;
}
