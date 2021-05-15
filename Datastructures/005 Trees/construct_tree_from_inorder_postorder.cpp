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

node* construct(int* postArray, int* inArray, int inStart, int inEnd){

    static int postIndex = inEnd; //postIndex starts from end

    if(inStart>inEnd){
        return nullptr;
    }

    int index=-1;
    for(int i=inStart; i<=inEnd; i++){
        if(postArray[postIndex]==inArray[i]){
            index = i;
            break;
        }
    }

    node* root = new node(postArray[postIndex--]);
    if(inStart==inEnd){
        return root;
    }

    root->rchild = construct(postArray, inArray, index+1, inEnd); // first construct right subtree
    root->lchild = construct(postArray, inArray, inStart, index-1);

    return root;

}

int main(){

    int postArray[] = {4, 5, 2, 6, 7, 3, 1};
    int inArray[] = { 4, 2, 5, 1, 6, 3, 7 };


    node* root = construct(postArray, inArray, 0, (sizeof(inArray)/sizeof(inArray[0]))-1);
    level_order(root);

return 0;
}
