#include<bits/stdc++.h>
int MIN_INT = 32768;
using namespace std;

class Node{
public:
    int data;
    Node* next = NULL;

    Node(int data){
        this->data=data;
    }
};
void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void display2(Node* head){
    if(head==NULL)
        return;
    cout<<head->data<<" ";
    display2(head->next);
}
int count(Node* head){
    if(head==NULL)
        return 0;
    return 1+count(head->next);
}
int sum(Node* head){
    if(head==NULL)
        return 0;
    return head->data+sum(head->next);
}
int min(Node* head){
    if(head==NULL)
        return MIN_INT;
    if(head->data<min(head->next))
        return head->data;
    else return min(head->next);
}
Node* recursiveRev(Node* head){

    if(head->next==NULL)
        return head;
    Node* newHead = recursiveRev(head->next);
    head->next->next= head;
    head->next=NULL;
    return newHead;

}
int main(){
    Node* head = new Node(6);
    head->next = new Node(8);
    head->next->next = new Node(100);
    head->next->next->next = new Node(201);
    display2(head);
    cout<<endl;
    cout<<count(head)<<endl;
    cout<<sum(head)<<endl;
    cout<<min(head)<<endl;
    display2(head);
    head = recursiveRev(head);
    cout<<endl;
    display2(head);

}
