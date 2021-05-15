#include<iostream>
using namespace std;

class  Queue{

private:
    int front, rear, size;
    int* Q;
public:
    Queue(){
        front=rear=-1;
        size = 10;
        Q = new int[size];
    }
    Queue(int size){
        front = rear=-1;
        this->size = size;
        Q = new int[this->size];
    }
    void enqueue(int x);
    int dequeue();
    void display();
};

void Queue::enqueue(int x){
    if(rear==size-1){
        cout<<"Queue is full"<<endl;
    }else{
        Q[++rear]=x;
    }
}
int Queue::dequeue(){
    int x =-1;
    if(front==rear){
        cout<<"Queue is empty"<<endl;
    }else{
        x=Q[front+1];
        front++;
        if(front=rear=size-1){
            front=rear=-1;
        }
        return x;
    }
    return x;
}
void Queue::display(){
    for(int i=front+1;i<=rear;i++){
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}

int main(){
    Queue q(5);
    q.enqueue(34);
    q.enqueue(99);
    q.enqueue(2234);
    q.display();
    q.dequeue();
    q.display();

return 0;
}
