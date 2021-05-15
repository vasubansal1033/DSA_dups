#include<bits/stdc++.h>
using namespace std;

class myPoint{

    int x;
    int y;
public:
    myPoint(int x, int y){
        this->x = x;
        this->y = y;
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
};

class myComparator{

public:
    int operator()( myPoint& p1,  myPoint& p2){ // passing by reference
        return p1.getX() > p2.getX();
    }

};

class myComparator2{

public:
    bool operator()(myPoint& p1, myPoint& p2){
        return pow(pow(p1.getX(), 2)+pow(p1.getY(), 2), 0.5) > pow(pow(p2.getX(), 2)+pow(p2.getY(), 2), 0.5);
    }

};
int main(){

    priority_queue<int> pq;
    pq.push(5);
    pq.push(99);
    pq.push(20);
    pq.push(42);
    pq.push(1);
    pq.push(-34);
    pq.push(39);

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;

    // creating a minheap
    priority_queue<int, vector<int>, greater<int> > minHeap;
    minHeap.push(5);
    minHeap.push(99);
    minHeap.push(20);
    minHeap.push(42);
    minHeap.push(1);
    minHeap.push(-34);
    minHeap.push(39);
    while(!minHeap.empty()){
        cout<<minHeap.top()<<" ";
        minHeap.pop();
    }
    cout<<endl;

    // user defined comparing
    priority_queue<myPoint, vector<myPoint>, myComparator2> p;
    p.push(myPoint(1, 9));
    p.push(myPoint(5, 20));
    p.push(myPoint(3, 34));
    p.push(myPoint(6, 49));
    p.push(myPoint(-1, 39));

    while(!p.empty()){
        myPoint temp = p.top();
        cout<<temp.getX()<<" "<<temp.getY()<<endl;
        p.pop();
    }

return 0;
}
