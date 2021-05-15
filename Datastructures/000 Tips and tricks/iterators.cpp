/*
STL algos always use two iterators, begin and end.
The end iterator points not to the last object but to the first
invalid object following the last one. Thus
c.begin()==c.end() iff c is empty. c.end()-c.begin()=c.size()

*/
#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int > v;
    for(int i=0; i<10; i++){
        v.push_back(i+1);
    }

    vector<int > v2(v.begin()+3, v.begin()+8);

    for(int i=0; i< v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    for(int i=0; i< v2.size(); i++){
        cout<<v2[i]<<" ";
    }
    cout<<endl;

    int data[] = {2,3,5,7,11,13,17,19,23,29,31};

    // Constructing vector from array
    // data w/o index is treated as a pointer, points at the first element
    // data + N points at last element

    vector<int> primes(data, data+(sizeof(data)/sizeof(data[0])));
    for(int i=0; i<primes.size(); i++){
        cout<<primes[i]<<" ";
    }
    cout<<endl;

    reverse(data+2, data+6); // works on vector as well
    for(int i=0; i<sizeof(data)/sizeof(data[0]); i++){
        cout<<data[i]<<" ";
    }

    cout<<endl;
    // similarly we have reverse iterators rbegin() and rend()
    for(vector<int >::iterator it = v.begin(); it!=v.end(); it++){
        cout<<*it<<" ";
//        *it++;
        (*it)++;
        cout<<*it<<endl;

    }

    int data2[5] = {1, 5, 4, 2, 3};
    vector<int > X(data2, data2+5);
    // This returns an iterator pointing to the found element
    cout<< typeid(find(X.begin(), X.end(), 2)).name() <<endl;
    //  Dereference the value iterator is pointing to.
    cout<< *(find(X.begin(), X.end(), 2)) <<endl;
    // This returns an integer
    cout<< typeid(find(X.begin(), X.end(), 2)-X.begin()).name() <<endl;
    // Index of the found element
    cout<< (find(X.begin(), X.end(), 2)-X.begin()) <<endl;

    // max_element returns the iterator
    cout<< *max_element(X.begin(), X.end())<<" "<< *min_element(X.begin(), X.end())<<endl;
    // Returns index of max and min element
    cout<< max_element(X.begin(), X.end())-X.begin()<<" "<< min_element(X.begin(), X.end())-X.begin()<<endl;

    vector<int >::iterator it = X.insert(X.begin()+1, 99); // returns iterator to inserted element
    cout<<*(it+1)<<endl;
    for(int i=0; i<X.size(); i++){
        cout<<X[i]<<" ";
    }
    cout<<endl;

    X.erase(X.begin()+1);
    for(int i=0; i<X.size(); i++){
        cout<<X[i]<<" ";
    }
    cout<<endl;

    X.erase(X.begin()+1, X.begin()+3);
    for(int i=0; i<X.size(); i++){
        cout<<X[i]<<" ";
    }
    cout<<endl;

    X.pop_back();
    for(int i=0; i<X.size(); i++){
        cout<<X[i]<<" ";
    }
    cout<<endl;






return 0;
}

