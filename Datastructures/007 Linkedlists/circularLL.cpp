#include<iostream>
using namespace std;


class Node{

public:
    int data;
    Node* next=NULL;

    Node(int data){
        this->data = data;
    }


};
void display(Node* head){

    if(head==NULL)
        return;
    Node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);

}
void displayRecursive(Node* head, Node* p){
    static int flag=0;
    if(flag==0 || p!=head){
        flag=1;
        cout<<p->data<<" ";
        displayRecursive(head, p->next);
    }
//    flag=0;

}
int main(){

    Node* head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(8);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = head;
    display(head);
    cout<<endl;
    displayRecursive(head, head);

return 0;
}
