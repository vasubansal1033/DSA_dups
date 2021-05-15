#include<bits/stdc++.h>
using namespace std;


class node{

public:
    int data;
    node* lchild = nullptr;
    node* rchild = nullptr;
    node(int data){
        this->data = data;
    }
};

node* input_tree(){

    cout<<"Enter root data: "<<endl;
    int temp;
    cin>>temp;
    node* root = new node(temp);
    queue <node* > q;
    q.push(root);
    while(!q.empty()){
        node* p = q.front();
        cout<<"Left y/n for "<<p->data<<" "<<endl;
        char c;
        cin>>c;
        if(c=='y'){
            cout<<"Enter left child of "<<p->data<<" "<<endl;
            int temp;
            cin>>temp;
            node* left_child = new node(temp);
            p->lchild = left_child;
            q.push(p->lchild);
        }
        cout<<"Right y/n of "<<p->data<<" "<<endl;
        cin>>c;
        if(c=='y'){
            cout<<"Enter right child of"<<p->data<<" "<<endl;
            int temp;
            cin>>temp;
            node* right_child = new node(temp);
            p->rchild = right_child;
            q.push(p->rchild);
        }
        q.pop();
    }
    return root;
}
void print_preorder(node* root){
    if(root==nullptr)
        return;
    cout<<root->data<<" ";
    print_preorder(root->lchild);
    print_preorder(root->rchild);
}
void print_inorder(node* root){
    if(root==nullptr)
        return;
    print_inorder(root->lchild);
    cout<<root->data<<" ";
    print_inorder(root->rchild);
}
void print_postorder(node* root){
    if(root==nullptr)
        return;
    print_postorder(root->lchild);
    print_postorder(root->rchild);
    cout<<root->data<<" ";
}


int main(){

    node* root = input_tree();
    print_preorder(root);
    //print_inorder(root);
    //print_postorder(root);

return 0;
}
