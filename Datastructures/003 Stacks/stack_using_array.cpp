#include<iostream>
using namespace std;

template<class T>
class Stack{

private:
    T* st;
    int size;
    int top;

public:
    Stack(){
        size=10;
        st = new T[size];
        top=-1;
    }
    Stack(int size){
        this->size = size;
        st = new T[this->size];
        top=-1;
    }

    void push(T x);
    T pop();
    T peek(int index);
    int stackTop();
    int isEmpty();
    int isFull();
    void display();


};

template<class T>
void Stack<T>::push(T x){
    if(isFull()){
        cout<<"Stack Overflow"<<endl;
    }else{
        top++;
        st[top]=x;
    }
}

template<class T>
T Stack<T>::pop(){
    T x =-1;
    if(isEmpty()){
        cout<<"Stack Underflow"<<endl;
    }else{
        x = st[top--];
    }
    return x;
}

template<class T>
T Stack<T>::peek(int index){
    T x =-1;
    if(index>top+1){
        cout<<"Invalid Index"<<endl;
    }else{
        x = st[top-index+1];
    }
    return x;
}

template<class T>
int Stack<T>::stackTop(){
    if(isEmpty()){
        return -1;
    }else return st[top];
}

template<class T>
int Stack<T>::isFull(){
//    if(size<=0){
//        return 1;
//    }
//    return 0;
    return top==size-1;
}
template<class T>
int Stack<T>::isEmpty(){
    return top==-1;
}

template<class T>
void Stack<T>::display(){
    for(int i=top;i>=0;i--)
        cout<<st[i]<<" ";
    cout<<endl;
}
int main(){

    Stack<char> stk(5);
    stk.push('a');
    stk.push('b');
    stk.push('c');
    stk.push('d');
    stk.push('e');
    stk.push('f');

    stk.display();
    cout<<stk.peek(5)<<endl;

return 0;
}
