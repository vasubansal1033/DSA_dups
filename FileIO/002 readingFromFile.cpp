#include<bits/stdc++.h>
#include<fstream>
using namespace std;


int main(){

    ifstream ifs;
    ifs.open("text1.txt"); // ios::in or ios::out for reading and writing respectively

    if(!ifs.is_open()) cout<<"The given file does not exist"<<'\n';
    else cout<<"File is opened!"<<'\n';

    while(!ifs.eof()){
        string str;
//        ifs>>str;
        getline(ifs, str);
        cout<<str<<"**";
    }
    ifs.close();

return 0;
}
