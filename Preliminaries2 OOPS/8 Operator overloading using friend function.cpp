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
    int getReal(){
        return real;
    }
    int getImag(){
        return imag;
    }
    void display(){
        cout<<this->real<<" + i"<<this->imag<<endl;
    }
    friend Complex operator+(Complex c1, Complex c2);

};
Complex operator+(Complex c1, Complex c2){
    Complex temp;
    temp.real=c1.real+c2.real;
    temp.imag=c1.imag+c2.imag;

    return temp;

}
int main(){

    Complex c1(10,20), c2(15,25);

    Complex c3=c1+c2;
    c3.display();

return 0;
}
