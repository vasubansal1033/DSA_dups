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

Node* mergeLL(Node* head1, Node* head2){

    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    Node* head3;
    Node* curr;

    if(head1->data<=head2->data){
        head3=curr=head1;
        head1=head1->next;
        curr->next=NULL;
    }else{
        head3=curr=head2;
        head2=head2->next;
        curr->next=NULL;
    }

    while(head1!=NULL && head2!=NULL){
        if(head1->data<=head2->data){
            curr->next=head1;
            curr=head1;
            head1=head1->next;
            curr->next=NULL;
        }else{
            curr->next=head2;
            curr=head2;
            head2=head2->next;
            curr->next=NULL;
        }
    }
    if(head1==NULL){
        curr->next=head2;
    }else{
        curr->next=head1;
    }

    return head3;

}
int main(){

    Node* head1 = new Node(2);
    Node* head2 = new Node(4);
    head1= insertSorted(head1, 8);
    head1= insertSorted(head1, 3);
    head1= insertSorted(head1, 7);
    head1= insertSorted(head1, 24);
    head1= insertSorted(head1, 0);

    head2= insertSorted(head2, 3);
    head2= insertSorted(head2, 7);
    head2= insertSorted(head2, 2);
    head2= insertSorted(head2, 5);
    head2= insertSorted(head2, 12);
    head2= insertSorted(head2, 10);
    head2= insertSorted(head2, 82);
    head2= insertSorted(head2, 15);
    head2= insertSorted(head2, 17);

    display(head1);
    cout<<endl;
    display(head2);
    cout<<endl;
    display(mergeLL2(head1, head2));


return 0;
}
