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
node* input(){

    cout<<"Enter data of head node: "<<endl;
    int temp; cin>>temp;
    node* head = new node(temp);
    queue<node*> q; q.push(head);
    while(!q.empty()){

        node* first = q.front();
        q.pop();
        cout<<"Enter left child for "<<first->data<<" y/n: "<<endl;
        char c; cin>>c;
        if(c=='y'){
            cout<<"Enter left child for "<<first->data<<": "<<endl;
            cin>>temp; node* leftChild = new node(temp);
            first->lchild = (leftChild);
            q.push(leftChild);
        }

        cout<<"Enter right child for "<<first->data<<" y/n: "<<endl;
        cin>>c;
        if(c=='y'){
            cout<<"Enter right child for "<<first->data<<": "<<endl;
            cin>>temp; node* rightChild = new node(temp);
            first->rchild = (rightChild);
            q.push(rightChild);
        }
    }
    return head;

}
void preOrder(node* root){

    if(root==nullptr)
        return;
    cout<<root->data<<" ";
    preOrder(root->lchild);
    preOrder(root->rchild);
}
void inOrder(node* root){

    if(root==nullptr)
        return;
    inOrder(root->lchild);
    cout<<root->data<<" ";
    inOrder(root->rchild);
}
void postOrder(node* root){

    if(root==nullptr)
        return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    cout<<root->data<<" ";
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
node* rBSTSearch(node* root, int target){

    if(root==nullptr || root->data == target){
        return root;
    }else if(root->data>target){
        return rBSTSearch(root->lchild, target);
    }
    return rBSTSearch(root->rchild, target);
}
node* iBSTSearch(node* root, int target){

    if(root==nullptr || root->data==target){
        return root;
    }
    while(root!=nullptr){
        if(root->data>target)
            root = root->lchild;
        else if(root->data<target)
            root = root->rchild;
        else return root;
    }
    return root;

}
node* rinsertBST(node* root, int data){

    if(root==nullptr){
        node* temp = new node(data);
        return temp;
    }
    if(root->data>data){
        root->lchild =  rinsertBST(root->lchild, data);
        return root;
    }
    root->rchild = rinsertBST(root->rchild, data);
    return root;

}
node* iinsertBST(node* root, int data){

    if(root==nullptr){
        node* temp = new node(data);
        return temp;
    }
    node* temp = root;
    while(temp->lchild!=nullptr && temp->rchild!=nullptr){
        if(temp->data>data){
            temp = temp->lchild;
        }else if(temp->data<data){
            temp = temp->rchild;
        }
    }
    if(temp->lchild && temp->rchild==nullptr){
        node* temp2 = new node(data);
        temp->rchild = temp2;
        return root;
    }
    if(temp->rchild && temp->lchild==nullptr){
        node* temp2 = new node(data);
        temp->lchild = temp2;
        return root;
    }
    if(temp->lchild==nullptr && temp->rchild==nullptr){
        if(temp->data>data){
            temp->lchild = new node(data);
        }else{
            temp->rchild = new node(data);
        }
    }
    return root;

}
void iterativePreorder(node* root){

    stack<node* > st;
    while(root!=nullptr || !st.empty()){

        if(root!=nullptr){
            cout<<root->data<<" ";
            st.push(root);
            root = root->lchild;
        }else{
            root = st.top(); st.pop();
            root = root->rchild;
        }
    }
}
void iterativeInorder(node* root){

    stack<node* > st;
    while(root!=nullptr || !st.empty()){

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
void iterativePostOrder(node* root){

    stack<node* > st;
    while(root!=nullptr || !st.empty()){

        if(root!=nullptr){
            st.push(root);
            root = root->lchild;
        }else{

            node* curr = st.top()->rchild;
            if(curr){
                root = curr;
            }else{

                curr = st.top(); st.pop();
                cout<<curr->data<<" ";
                while(!st.empty() && curr == st.top()->rchild){
                    curr = st.top(); st.pop();
                    cout<<curr->data<<" ";
                }

            }

        }

    }

}
void levelOrder(node* root){

    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* curr = q.front();
        q.pop();

        if(curr){
            cout<<curr->data<<" ";
            q.push(curr->lchild); q.push(curr->rchild);
        }

    }

}
node* construct(int* preArray, int* inArray, int inStart, int inEnd){

    static int preIndex = 0;

    if(inStart>inEnd)
        return nullptr;

    int index = -1; // holds index of current preArray element in Inorder array
    for(int i=inStart; i<=inEnd; i++){
        if(preArray[preIndex] == inArray[i]){
            index = i;
            break;
        }
    }

    node* root = new node(preArray[preIndex]);
    preIndex++;
    if(inStart == inEnd)
        return root;

    root->lchild = construct(preArray, inArray, inStart, index-1);
    root->rchild = construct(preArray, inArray, index+1, inEnd);

    return root;

}
node* construct2(int* postArray, int* inArray, int inStart, int inEnd){

    static int postIndex = inEnd;
    if(inStart>inEnd)
        return nullptr;

    int index = -1;
    for(int i=inStart; i<=inEnd; i++){
        if(inArray[i] == postArray[postIndex]){
            index = i;
            break;
        }
    }

    node* root = new node(postArray[postIndex]);
    postIndex--;

    if(inStart==inEnd)
        return root;

    root->rchild = construct2(postArray, inArray, index+1, inEnd);
    root->lchild = construct2(postArray, inArray, inStart, index-1);
    return root;



}
int height(node* root){

    if(root==nullptr)
        return 0;

    int x = height(root->lchild);
    int y = height(root->rchild);
    if(x>y)
        return x+1;
    else return y+1;

}

int main(){

    node* root = test_input();
    preOrder(root);
    cout<<endl;
    iterativePreorder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    iterativeInorder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    iterativePostOrder(root);
    cout<<endl;
    levelOrder(root);
    cout<<endl;

    int preArray[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inArray[] =  {7, 6, 9, 3, 4, 5, 8, 2, 1};

    node* root2 = construct(preArray, inArray, 0, (sizeof(preArray)/sizeof(preArray[0]))-1);
    levelOrder(root2);
    cout<<endl;

    int postArray[] = {4, 5, 2, 6, 7, 3, 1};
    int inArray2[] = { 4, 2, 5, 1, 6, 3, 7 };

    node* root3 = construct2(postArray, inArray2, 0, (sizeof(postArray)/sizeof(postArray[0]))-1);
    levelOrder(root3);



return 0;
}
