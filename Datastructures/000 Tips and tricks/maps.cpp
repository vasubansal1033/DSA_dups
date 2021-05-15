#include<bits/stdc++.h>
using namespace std;


int main(){
/*
Map is similar to a set. set only has values
but map has key, value pairs.
*/

    map<string , int> m;
    m["vasu"] = 1;
    m["bansal"] = 2;
    m["aaa"] = 3;
    cout<<m["vasu"]+m["bansal"]<<endl;

    // values are stored according to the first element
    for(auto i = m.begin(); i!= m.end(); i++){
        cout<<i->first<<" "<<i->second<<endl;
    }
    for(auto i : m){ // i is a pair
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;

    string str = "bansal";
    if(m.find(str)!=m.end()){
        m.erase(m.find(str));
//        m.erase(str);
    }
    m.insert(make_pair("parv", 0));
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;




return 0;
}
