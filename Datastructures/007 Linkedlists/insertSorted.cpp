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

Node* insertSorted(Node* head, int data){
    Node* temp = new Node(data);

    if(head==NULL){ // no node
        return temp;
    }
    if(head->next==NULL){ // single node
        if(head->data>=data){
            temp->next = head;
            head = temp;
            return head;
        }else{
            head->next = temp;
            return head;
        }
    }
    if(head->data>data){
        temp->next= head;
        head = temp;
        return head;
    }
    Node* it = head;
    while(it->next!=NULL && it->next->data<data){
        it = it->next;
    }
    if(it->next==NULL){
        it->next = temp;
        return head;
    }
    temp->next = it->next;
    it->next = temp;
    return head;
}
int main(){

    Node* head = insertSorted(NULL, 89);


    head = insertSorted(head, 234);
    head = insertSorted(head, 99);
    head = insertSorted(head, 1291);
    head = insertSorted(head, 93);
    head = insertSorted(head, 93);

    head = insertSorted(head, 0);
    display(head);

return 0;
}
