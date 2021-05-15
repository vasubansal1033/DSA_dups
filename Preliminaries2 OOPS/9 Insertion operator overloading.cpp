#include<iostream>
using namespace std;


class Complex{

private:
    int real, imag;

public:
    Complex(int real=0, int imag=0){
        this->real=real;
        this->imag=imag;
    }
    friend ostream& operator<<(ostream &o, Complex& c1);

};
ostream& operator<<(ostream& o, Complex& c1){
    o<<c1.real<<" + i"<<c1.imag<<endl;
}
int main(){

    Complex c1(10,20);
    cout<<c1<<endl;

return 0;
}
