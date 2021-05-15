#include<iostream>
using namespace std;

class node{

public:
    int data;
    node* next;
};

class Stack{

private:
    node* top;
public:
    Stack(){
        top = NULL;
    }
    void push(int x);
    int pop();
    void display();
};

void Stack::push(int x){

    node *t = new node();
    if(t==NULL){
        cout<<"Stack is full"<<endl;
    }
    t->data = x;
    t->next = top;
    top = t;
}
int Stack::pop(){

    int x =-1;
    if(top==NULL){
        cout<<"Stack is empty"<<endl;
        return x;
    }
    x = top->data;
    node* t = top;
    top = top->next;
    delete(t);
    return x;

}

void Stack::display(){

    node* p = top;
    if(p==NULL){
        cout<<"Stack is Empty"<<endl;
    }
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;

}

int main(){

    Stack stk;
    stk.push(4);
    stk.push(1);
    stk.push(9);
    stk.display();
    cout<<stk.pop()<<endl;
    stk.display();

return 0;
}
