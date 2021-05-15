#include<bits/stdc++.h>
#include<fstream>
using namespace std;

class student{
public:
    string name; int rollNo; string dept;

    friend ofstream& operator<<(ofstream& o, student& s);
    friend ifstream& operator>>(ifstream& i, student& s);
};

ofstream& operator<<(ofstream& o, student& s){
    o<<s.name<<'\n';
    o<<s.rollNo<<'\n';
    o<<s.dept<<'\n';

    return o;
}
ifstream& operator>>(ifstream& i, student& s){
//    i>>s.name>>s.rollNo>>s.dept;
    getline(i, s.name);
    getline(i, s.rollNo);
    getline(i, s.dept);

    return i;
}
int main(){

    student s1;
    s1.name = "Vasu Bansal";
    s1.rollNo = 160776;
    s1.dept = "Mechanical";

//    ofstream ofs; ofs.open("student1.txt", ios::trunc);
//    ofs<<s1.name<<'\n';
//    ofs<<s1.rollNo<<'\n';
//    ofs<<s1.dept<<'\n';
    ofstream ofs; ofs.open("student2.txt", ios::trunc);
    ofs<<s1;
    ofs.close();

    ifstream ifs; ifs.open("student1.txt");
    if(!ifs.is_open()) cout<<"File not found!"<<'\n';
    else cout<<"File is found!"<<'\n';

    student s2;
    ifs>>s2;

    cout<<s2.name<<" "<<s2.rollNo<<" "<<s2.dept<<'\n';
    ifs.close();

return 0;
}
