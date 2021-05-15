#include<bits/stdc++.h>
#include<fstream>
using namespace std;


int main(){

//    ofstream ofs("text1.txt", ios::trunc);
    ofstream ofs;
    ofs.open("text1.txt", ios::trunc);

    ofs<<"Vasu Bansal"<<'\n';
    ofs<<160776<<'\n';
    ofs<<"Mechanical and Aerospace"<<'\n';

    ofs.close();

    ofstream ofs1("text1.txt", ios::app);
    ofs1<<"Hello world!!"<<'\n';

    ofs1.close();

return 0;
}
