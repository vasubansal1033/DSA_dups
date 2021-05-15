#include<bits/stdc++.h>
using namespace std;


int main(){

    string str;
    cin>>str; // does not take in space
    cout<<str<<endl;

    getline(cin, str); // takes in a line, ie until enter is hit
    cout<<str<<endl;

    str = "Vas";
    str.push_back('u');
    cout<<str<<endl;
    str.pop_back();
    cout<<str<<endl;

    cout<<"The capacity of string "<<str.capacity()<<" can be greater than size: "<<str.size()<<endl;
    str.resize(20);
    str.shrink_to_fit(); // makes capacity equal to size
    cout<<"The capacity of string "<<str.capacity()<<" can be greater than size: "<<str.size()<<endl;
    str.push_back('u');
    cout<<str<<endl;

    cout<<"---------------"<<endl;

    str = "Vasu Bansal";
    string::iterator it;
    it = str.begin();
    cout<<typeid(it).name()<<endl;
    cout<<*it<<endl;

    str = "Vasu_Bansal";
    char ch[80];
    str.copy(ch, 4, 0);
    cout<<"The copied array: "<<ch<<endl;

    string str1 = "string 1";
    string str2("string 2");

    str1.swap(str2);
    cout<<str1<<" "<<str2<<endl;

    cout<<str.substr(1, 5)<<endl;





return 0;
}
