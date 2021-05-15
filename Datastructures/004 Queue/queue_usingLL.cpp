#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class Queue{

private:
    Node* front = NULL;
    Node* rear = NULL;
public:
    void enqueue(int x);
    int dequeue();
    void display();

};
void Queue::enqueue(int x){
    Node* t = new Node;
    if(t==NULL){
        cout<<"Queue is full"<<endl;
    }else{

        t->data = x;
        t->next = NULL;
        if(front==NULL){
            front = rear = t;
        }else{
            rear->next = t;
            rear = t;
        }
    }
}
int Queue::dequeue(){
    int x =-1;
    if(front==NULL){
        cout<<"Queue is empty";
    }else{
        Node* t = front;
        x = t->data;
        front = front->next;
        free(t);
    }
    return x;
}
void Queue::display(){
    if(front==NULL){
        cout<<"Queue is empty"<<endl;
        return;
    }
    Node* p = front;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main(){

    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();
    q.dequeue();
    q.display();

return 0;
}
