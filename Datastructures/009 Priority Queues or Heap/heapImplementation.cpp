#include<bits/stdc++.h>
using namespace std;


class heap{

public:

    vector<int> v;
    heap(){
    }
    // build heap constructor
    heap(vector<int> vec){
        this->v = vec;

        for(int i=v.size()/2-1; i>=0; i--){

            int k = i;
            // j points to the larger child of i
            int j = 2*k+1; // make j as left child

            while(j<=v.size()-1){

                // if right is greater then make j as right child
                if(j+1<v.size() && v[j]<v[j+1]){
                    j++;
                }

                // swap child with root, pushing it upwards
                if(v[k]<v[j]){
                    swap(v[k], v[j]);
                    k = j;
                    j = 2*k+1;
                }
                else break;

            }

        }


    }
    // insert an element in heap
    void insert_(int m){

        v.push_back(m);

        int idx = v.size()-1;
        while(idx>=0){

            int parentIdx = (idx%2!=0)?(idx/2):(idx/2)-1;
            if(v[parentIdx]<=v[idx]){
                swap(v[parentIdx], v[idx]);
//                idx = (idx%2!=0)?idx/2:(idx/2)-1;
                idx = parentIdx;
            }
            else break;
        }

    }
    // delete the highest priority element from heap
    void pop_(){

        if(v.size()==0)
            return;

        swap(v[0], v[v.size()-1]);
        v.pop_back();

        int idx = 0;
        while(2*idx+1<v.size() && 2*idx+2<v.size()){

            int p1(2*idx+1), p2(2*idx+2);

            if(v[idx]>max(v[p1], v[p2])) break;

            if(v[p1]<v[p2]){
                swap(v[idx], v[p2]);
                idx = p2;
            }else{
                swap(v[idx], v[p1]);
                idx = p1;
            }
        }


        if(v.size()==2){
            if(v[0]<v[1]) swap(v[0], v[1]);
        }

    }
    int top_(){

        if(v.size()==0){
            return INT_MAX;
        }

        return v[0];
    }
    bool empty_(){
        return v.empty();
    }
    void print_(){
        for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    }

};
int main(){

    heap h; //({2, -24, 45, 999, 98, 0});
    h.insert_(2);
    h.insert_(-24);
    h.insert_(45);
    h.insert_(45);
    h.insert_(999);
    h.insert_(999);
    h.insert_(999);
    h.insert_(45);
    h.insert_(98);
    h.insert_(-123);
    h.insert_(12438);

//    h.print_();
//    cout<<'\n';

    while(!h.empty_()){
        cout<<h.top_()<<" ";
//        h.print_();
//        cout<<'\n';
        h.pop_();
    }

return 0;
}
