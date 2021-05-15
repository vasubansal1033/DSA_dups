#include<bits/stdc++.h>
using namespace std;


int main(){

    pair<int , char> p1;
    p1.first = 100;
    p1.second = 'G';
    cout<<p1.first<<" "<<p1.second<<endl;

    // Different ways of initialization
    pair<int, string> p2(1, "Vasu");
    cout<<p2.first<<" "<<p2.second<<endl;

    pair<int, string> p3(p2);
    cout<<p3.first<<" "<<p3.second<<endl;
    p3 = make_pair(100, "vASU");
    cout<<p3.first<<" "<<p3.second<<endl;
    cout<< (p3>p2) <<endl; // comparison based on first element
    p2.first = 100;
    cout<< (p3<p2) <<endl;
    p2.swap(p3); // swaps contents for same types


return 0;
}
