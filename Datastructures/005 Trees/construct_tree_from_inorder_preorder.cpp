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


node* construct(int* preArray, int* inArray, int inStart, int inEnd){

    static int preIndex = 0;

    if(inStart>inEnd){
        return nullptr;
    }

    int index = -1;
    for(int i=inStart;i<=inEnd;i++){
        if(preArray[preIndex]== inArray[i]){
            index = i;
            break;
        }
    }

    node* root = new node(preArray[preIndex++]);
    if(inStart==inEnd){
        return root;
    }

    root->lchild = construct(preArray, inArray, inStart, index-1);
    root->rchild = construct(preArray, inArray, index+1, inEnd);

    return root;


}

int main(){

    int preArray[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inArray[] =  {7, 6, 9, 3, 4, 5, 8, 2, 1};

    node* root = construct(preArray, inArray, 0, (sizeof(preArray)/sizeof(preArray[0]))-1);
    level_order(root);
    cout<<endl;

return 0;
}
