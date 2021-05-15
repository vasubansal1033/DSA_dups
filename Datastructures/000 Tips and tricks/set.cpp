#include<bits/stdc++.h>
using namespace std;

void predecessor(set<int >& s, int key){

    set<int>::iterator it = s.find(key);
    if(it==s.end()){
        cout<<"Key not found"<<endl;
        return;
    }
    if(it==s.begin()){
        cout<<"First element, no predecessor"<<endl;
        return;
    }
    it--;
    cout<<"Predecessor of "<<key<<"is: "<<*it<<endl;
}
void sucessor(set<int >& s, int key){

    set<int >::iterator it = s.find(key);
    if(it==s.end()){
        cout<<"Key not found"<<endl;
        return;
    }
    it++;
    if(it==s.end()){
        cout<<"Last element, no successor"<<endl;
        return;
    }
    cout<<"Successor of "<<key<<"is "<<*it<<endl;


}
int main(){
/*
Sets store only unique elements.
Sets can add, remove, find a particular element
in log(n) time. They're implemented using
Binary Search trees.
*/
    set<int > s;
    for(int i=1;i<=100; i++){
        s.insert(i);
    }
    s.insert(42); // does nothing
    for(int i=1; i<=100; i+=2){
        s.erase(i);
    }
    cout<<s.size()<<endl;

    // no indexing for set
    for(set<int>::iterator it = s.begin(); it!=s.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    set<int, greater<int> > s2(s.begin(), s.end());
    for(set<int>::iterator it = s2.begin(); it!=s2.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    // delete elements greater than 30
    s2.erase(s2.begin(), s2.find(30));
    for(set<int>::iterator it = s2.begin(); it!=s2.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    // delete element by value
    s2.erase(26);
    for(set<int>::iterator it = s2.begin(); it!=s2.end(); it++){
        cout<<*it<<" ";
    }
    s.clear();
    s2.clear();
    cout<<endl;
    cout<<"---------------"<<endl;
    for(int i=0; i<5; i++){
        s.insert(i*5);
        s2.insert(i*5);
    }

    for(auto i=s.begin(); i!=s.end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    for(auto i:s2){
        cout<<i<<" ";
    }
    cout<<endl;

    int a = 10;
//    a = 9;
    // lower bound is like less than equal to
    // upper bound is like strictly greater than
    cout<<*s.lower_bound(a)<<" "<<*s.upper_bound(a)<<endl;
    cout<<*s2.lower_bound(a)<<" "<<*s2.upper_bound(a)<<endl;
/*
Actually, lower bound(a) returns the 'iterator' to
first element which will definitely not come before
a in the set/vector
upper bound(a) will give the iterator to the first
element which will definitely come after a in the
set.
*/
    // sets have an interval constructor as well
    int data[5] = {1,5, 2, 3, 4};
    set<int > sdata(data, data+5);
    for(auto i: sdata)
        cout<<i<<" ";
    cout<<endl;

    // easy way of sorting and removing duplicates from a vector
    int dataX[] = {1, 9, 8, 2 , 32, 2 , 9 ,23 , 32, 1, 7, 7, 8, 1, 34};
    vector<int > vec(dataX, dataX+sizeof(dataX)/sizeof(dataX[0]));
    set<int > svector(vec.begin(), vec.end());
    vector<int > vec2(svector.begin(), svector.end());

    for(auto i:vec2)
        cout<<i<<" ";


return 0;
}
