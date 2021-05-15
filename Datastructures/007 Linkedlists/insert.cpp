#include<iostream>
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

Node* insert(Node* head, int index, int data){
    if(head==NULL){
        Node* temp = new Node(data);
        return temp;
    }
    if(index==0){
        Node* temp= new Node(data);
        temp->next=head;
        head= temp;
        return head;
    }
    Node* temp = new Node(data);
    Node* it = head;
    for(int i=1;i<index;i++){
        it = it->next;
    }
    temp->next = it->next;
    it->next = temp;
    return head;
}
int main(){

    Node* head = insert(NULL,0, 89);
    head = insert(head, 1, 93);
    head = insert(head, 2, 99);
    head = insert(head, 3, 234);
    head = insert(head, 4, 1231);
    head = insert(head, 4 ,0);
    display(head);

return 0;
}
