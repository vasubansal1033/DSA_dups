#include<bits/stdc++.h>
using namespace std;

void vector_demo(){

    vector<int > v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(100);
    v.push_back(100);
    v.push_back(100);
    v.push_back(100);
    v.push_back(100);
    v.push_back(123);

    auto it = lower_bound(v.begin(), v.end(), 100); // 100
    auto it2 = upper_bound(v.begin(), v.end(), 100); // 123
    cout<<it2-it<<endl;

}
int main(){

    map<char, int> cnt; // by default maps store 0 value of value

    string str = "Vasu Bansal";

    for(auto x:str){
        cnt[x]++;
    }
    cout<<cnt['z']<<" "<<cnt['a']<<endl;

    map<int, vector<int> > test;
    cout<<test[0].size()<<endl;

    vector<int> test_vec;
    cout<<test_vec.size()<<endl;

    // check if given number lies in set of intervals

    set<pair<int, int> >intervals;
    intervals.insert({2, 3});
    intervals.insert(make_pair(10, 20));
    intervals.insert({401, 450});
    intervals.insert({30, 400});

    int a = 1;

    auto p1 = intervals.upper_bound({a, INT_MAX});
    p1--;
    // pair<int, int> p11 = *p1

    if(p1->first<=a && p1->second>=a){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }


return 0;
}
