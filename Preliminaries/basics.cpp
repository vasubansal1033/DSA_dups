#include<iostream>
using namespace std;

enum days{mon,tue = 2,wed,thu,fri = 10,sat};
typedef int marks;
typedef int rollno;
int main(){

    cout<<"Hello World"<<endl;
    cout<<"My name is Vasu"<<endl;

    for(int i=0;i<10;i++){
        cout<<"5 X "<<i<<" = "<<5*i<<endl;
    }

    days d;
    d = sat;
    cout<<sat<<endl;
    cout<<mon<<endl<<tue<<endl<<wed<<endl<<thu<<endl<<fri<<endl<<sat<<endl;

    marks m1=90, m2=85, m3 = 23; // Both of these are integers
    rollno r1 = 1, r2 =2, r3=3;

    int i=0;
    while(i<5){
        cout<<i<<endl;
        i++;
    }
    i=0;
    do{
        cout<<i<<endl;
        i++;
    }while(i<5);

    int a;
    a = 10<<2;
    cout<<a<<endl;
    a = 10>>2;
    cout<<a<<endl;
    cout<<(15&2)<<endl;
    cout<<(15|2)<<endl;
    cout<<(15^2)<<endl;
    cout<<(~15)<<endl;

    string name;
    cout<<"Enter your name: "<<endl;
//    cin>>name;
//    cout<<"Your name is "<<name<<endl;
    getline(cin, name);
    cout<<"Your name is "<<name<<endl;

    int b = 6, c;
    a = 5;
    c = ++a * b;
    cout<<a<<" "<<b<<" "<<c<<endl;

    int day=7;

    switch(day){
        case 1: cout<<"monday";
                break;
        case 2: cout<<"tuesday";
                break;
        case 3: cout<<"wednesday";
                break;
        default: cout<<"day";
    }

return 0;
}
