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

node* test_input(){
    node* root = new node(1);
    root->lchild = new node(2);
    root->rchild = new node(3);
    root->lchild->lchild = new node(4);
    root->lchild->rchild = new node(5);
    root->rchild->lchild = new node(6);
    root->rchild->rchild = new node(7);
    return root;
}

void iterative_preorder(node* root){

    stack <node* > st;
    while(!(root==nullptr && st.empty())){
        if(root!=nullptr){
            cout<<root->data<<" ";
            st.push(root);
            root = root->lchild;
        }else{
            root = st.top();
            st.pop();
            root = root->rchild;
        }
    }


}
void iterative_inorder(node* root){

    stack <node* > st;

    while(!(root==nullptr && st.empty())){
        if(root!=nullptr){
            st.push(root);
            root = root->lchild;
        }else{
            root = st.top();
            st.pop();
            cout<<root->data<<" ";
            root = root->rchild;
        }
    }
}

// 0->left child
// 1->right child
// 2-> current node
void iterative_postorder(node* root){

//    stack < pair<node*, int>> st;
//    pair< node*, int> p;
//    p = make_pair(root, 0);
//    st.push(p);
//    while(!st.empty()){
//
//        p = st.top();
//        st.pop();
//        if(p.first==nullptr){
//            continue;
//        }
//        if(p.second==0){
//            p = make_pair(p.first, 1);
//            st.push(p);
//            if(p.first->lchild){
//                p = make_pair(p.first->lchild, 0);
//                st.push(p);
//            }
//        }else if(p.second==1){
//            p = make_pair(p.first, 2);
//            st.push(p);
//            if(p.first->rchild){
//                p = make_pair(p.first->rchild, 0);
//                st.push(p);
//            }
//        }else if(p.second==2){
//            cout<<p.first->data<<" ";
//        }
//    }
    stack <node* > st;
    while(!(root==nullptr && st.empty())){
        if(root!=nullptr){
            st.push(root);
            root = root->lchild;
        }else{
            node* temp = st.top()->rchild;
            if(temp){ // check if the node has a right subtree. if it has, move node there.
                root = temp;
            }else{
                temp = st.top();
                st.pop();
                cout<<temp->data<<" "; // at this point, we are sure that temp has no left child as well as right child, so print
                while(!st.empty() && temp == st.top()->rchild){
                    temp = st.top(); // after printing the right child in prev step, print the node itself now.
                    st.pop();
                    cout<<temp->data<<" ";
                }

            }

        }
    }
    cout<<endl;
}
void level_order(node* root){
    queue< node* > q;
    cout<<root->data<<" ";
    q.push(root);
    while(!q.empty()){
        if(q.front()->lchild){
            cout<<q.front()->lchild->data<<" ";
            q.push(q.front()->lchild);
        }
        if(q.front()->rchild){
            cout<<q.front()->rchild->data<<" ";
            q.push(q.front()->rchild);
        }
        q.pop();
    }
}
int count_(node* root){

    if(root==nullptr){
        return 0;
    }
    return count_(root->lchild)+count_(root->rchild)+1;
}
int height(node* root){

    if(root==nullptr){
        return 0;
    }
    int x = height(root->lchild);
    int y = height(root->rchild);
    if(x>y){
        return x+1;
    }else{
        return y+1;
    }
}
int fun(node* root){

    if(root==nullptr){
        return 0;
    }
    int x = fun(root->lchild);
    int y = fun(root->rchild);
    if(root->lchild==nullptr && root->rchild==nullptr){ // count leaf nodes. change this condition to get primary, secondary etc.
        return x+y+1;
    }else{
        return x+y;
    }


}
int main(){

    node* root = test_input();
    iterative_postorder(root);
    iterative_inorder(root);
    cout<<endl;
    level_order(root);
    cout<<endl;
    cout<<count_(root)<<" "<<height(root)<<endl;
    cout<<fun(root)<<endl;

return 0;
}
