#include<iostream>
using namespace std;


class test{

private:
    int a;
    int* p;

public:
    test(int len){
        a=len;
        p=new int[a];
    }
    test(test &t){
        a=t.a;
//        p=t.p;
        p=new int[a]; // Copies of dynamically memory are allocated in Deep Copy contructors
        for(int i=0;i<a;i++){
            p[i]=(t.p)[i];
        }
    }
    int getA(){
        return a;
    }
    int* getP(){
        return p;
    }
    void print(){
        for(int i=0;i<a;i++)
            cout<<p[i]<<" ";
        cout<<endl;
    }
};
int main(){

    test t1(5);
    cout<<t1.getA()<<" "<<t1.getP()<<endl;
    for(int i=0;i<t1.getA();i++){
        (t1.getP())[i]=i+1;
    }

    t1.print();

    test t2(t1);
    cout<<t2.getA()<<" "<<t2.getP()<<endl;
    t2.print();

return 0;
}
