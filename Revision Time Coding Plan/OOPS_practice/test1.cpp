#include<bits/stdc++.h>
using namespace std;

class rectangle{
private:
    int l, r;

public:
    rectangle(int l=0, int r=0){
        this->l = l;
        this->r = r;
    }
    int getL(){
        return this->l;
    }
    int getR(){
        return this->r;
    }
    void setL(int l){
        this->l = l;
    }
    void setR(int r){
        this->r = r;
    }
    int area(){
        return l*r;
    }
    int perimeter(){
        return 2*(l+r);
    }
};
class testArray{
public:
    int sze;
    int* a;
    testArray(int n){
        this->sze = n;
        this->a = new int[n];
        for(int i=0; i<n; i++) a[i] = i;
    }
    testArray(testArray& c){
//        delete[] a;
        this->sze = c.sze;
        this->a = new int[this->sze];
        for(int i=0; i<sze; i++) a[i] = (c.a)[i];
    }
    void display(){
        for(int i=0; i<sze; i++) cout<<a[i]<<" ";
    }
    int getS(){
        return sze;
    }
    int* getA(){
        return a;
    }

};
class myClass{
public:
    void fun1(){
        cout<<"Inline"<<'\n';
    }
    void fun2();
    inline void fun3();

};
void myClass::fun2(){
    cout<<"Nonline"<<'\n';
}
void myClass::fun3(){
    cout<<"Inline"<<'\n';
}
class complexNo{
private:
    int real, imag;
public:
    complexNo(int r = 0, int i = 0){
        this->real = r;
        this->imag = i;
    }
    int getR(){
        return real;
    }
    int getI(){
        return imag;
    }
    void setR(int r){
        this->real = r;
    }
    void setI(int i){
        this->imag = i;
    }
    void display(){
        cout<<this->real<<" "<<this->imag<<'\n';
    }
    complexNo addition(complexNo c2){
        complexNo res(this->real+c2.real, this->imag+c2.imag);
        return res;
    }
    friend complexNo operator+(complexNo c1, complexNo c2);
    friend ostream& operator<<(ostream& o, complexNo& c);
    friend istream& operator>>(istream& i, complexNo& c);

};
complexNo operator+(complexNo c1, complexNo c2){
    complexNo res = complexNo(c1.getR()+c2.getR(), c1.getI()+c2.getI());
    return res;
}
ostream& operator<<(ostream& o, complexNo& c){
    o<<c.getR()<<"+"<<c.getI()<<"i";
    return o;
}
istream& operator>>(istream& i, complexNo& c){
    int a, b;
    cout<<"Enter real and imaginary parts: ";
    i>>a>>b;
    c.setR(a);
    c.setI(b);
    return i;
}

int main(){

    complexNo c1(20, 30), c2(40, 50);
    auto c3 = c1+c2;
    c3.display();
    cout<<c3;

    complexNo c4;
    cin>>c4;
    cout<<c4<<" "<<c3;

return 0;
}
