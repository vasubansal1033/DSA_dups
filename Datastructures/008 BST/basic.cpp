#include<bits/stdc++.h>
using namespace std;

class node{

public:
    int data;
    node* lchild=nullptr;
    node* rchild=nullptr;

    node(int data){
        this->data = data;

    }
};

node* test_input(){
    node* root = new node(30);
    root->lchild = new node(20);
    root->rchild = new node(40);
    root->lchild->lchild = new node(10);
    root->lchild->rchild = new node(25);
    root->rchild->lchild = new node(35);
    root->rchild->rchild = new node(50);
    return root;
}
node* rsearch_bst(node* root, int data){

    if(root==nullptr || root->data == data){
        return root;
    }
    if(root->data>data){
        return rsearch_bst(root->lchild, data);
    }
    return rsearch_bst(root->rchild, data);
}
node* isearch_bst(node* root, int data){

    if(root==nullptr){
        return nullptr;
    }
    while(root!=nullptr){
        if(root->data>data){
            root = root->lchild;
        }else if(root->data<data){
            root = root->rchild;
        }else{
            return root;
        }
    }
    return root;

}
node* rinsert_bst(node* root, int data){

    if(root==nullptr){
        node* temp = new node(data);
        return temp;
    }
    if(root->data>data){
        root->lchild = rinsert_bst(root->lchild, data);
        return root;
    }
    root->rchild = rinsert_bst(root->rchild, data);
    return root;
}
node* iinsert_bst(node* root, int data){

    // base case, make a node and return its pointer
    if(root==nullptr){
        node* temp = new node(data);
        return temp;
    }

    node* temp = root;
    // traverse in the tree to find a location until both lchild and rchild are not null
    while(temp->lchild!=nullptr && temp->rchild!=nullptr){
        if(temp->data>data){
            temp = temp->lchild;
        }else if(temp->data<data){
            temp = temp->rchild;
        }
    }
    // if only lchild exists, and rchild is null, it means we have to insert in the right side of temp
    if(temp->lchild && temp->rchild==nullptr){
        node* temp2 = new node(data);
        temp->rchild = temp2;
        return root;
    }
    // if only rchild exists, and lchild is null, it means we have to insert in the left side of temp
    if(temp->rchild && temp->lchild==nullptr){
        node* temp2 = new node(data);
        temp->lchild = temp2;
        return root;
    }
    // if both are null, check with temp's data, whether to insert left or right
    if(temp->lchild==nullptr && temp->rchild==nullptr){
        if(temp->data>data){
            temp->lchild = new node(data);
        }else{
            temp->rchild = new node(data);
        }
    }
    return root;

}
node* minElement(node* root){

    if(root==nullptr || root->lchild==nullptr)
        return root;

    while(root->lchild!=nullptr)
        root = root->lchild;
    return root;
}
node* deleteNode(node* root, int data){

    if(root==nullptr)
        return root;

    if(root->data>data)
        root->lchild = deleteNode(root->lchild, data);
    else if(root->data<data)
        root->rchild = deleteNode(root->rchild, data);
    else{

        // If the node to be deleted has a single child, delete the node and return the single child
        if(root->lchild==nullptr){
            node* temp = root->rchild;
            free(root);
            return temp;
        }else if(root->rchild==nullptr){
            node* temp = root->lchild;
            free(root);
            return temp;
        }
        // both children are present. So, find the inorder successor i.e. minimum element in right subtree
        node* temp = minElement(root->rchild);
        root->data = temp->data; // overwrite the root's data with inorder successor's data
        root->rchild = deleteNode(root->rchild, temp->data); // recursively delete inorder successor which will be in right subtree
    }

    return root;

}

void inOrder(node* root){

    if(root==nullptr)
        return;
    inOrder(root->lchild);
    cout<<root->data<<" ";
    inOrder(root->rchild);
}
void preOrder(node* root){
    if(root==nullptr)
        return;
    cout<<root->data<<" ";
    preOrder(root->lchild);
    preOrder(root->rchild);
}

int isBSTutil(node* root, int mini, int maxi){

    if(root==nullptr) // empty tree is a BST
        return 1;

    if(root->data>maxi || root->data<mini)
        return 0;

    return isBSTutil(root->lchild, mini, root->data) && isBSTutil(root->rchild, root->data, maxi);

}
int isBST(node* root){
    return isBSTutil(root, INT_MIN, INT_MAX);
}

int isBSTutil2(node* root, node* left, node* right){

    if(root==nullptr)
        return 1;

    if(left!=nullptr && root->data<= left->data)
        return 0;
    if(right!=nullptr && root->data>=right->data)
        return 0;
    return isBSTutil2(root->lchild, left, root) && isBSTutil2(root->rchild, root, right);

}
int isBST2(node* root){
    return isBSTutil2(root, nullptr, nullptr);
}

//-----------------------------------------------------------------------------------

// Constructing BST from preorder - Recursive way

node* constructUtil(int* preOrder, int n, int mini, int maxi){

    static int preIndex = 0;
    if(preIndex>n)
        return nullptr;

    node* root = nullptr;
    if(preOrder[preIndex]>mini && preOrder[preIndex]<maxi){
        root = new node(preOrder[preIndex]);
        preIndex++;
        if(preIndex<=n){

        root->lchild = constructUtil(preOrder, n, mini, preOrder[preIndex-1]);
        root->rchild = constructUtil(preOrder, n, preOrder[preIndex-1], maxi);

        }
    }

    return root;

}
node* construct(int* preOrder, int n){ // n is the last index of preOrder array
    return constructUtil(preOrder, n, INT_MIN, INT_MAX);
}

//-----------------------------------------------------------------------------------

// Constructing BST from preorder - Iterative way - using stack

// utility function, returns INT_MAX if stack is empty, other wise the data of the node of stack's top
int checkStackTop(stack<node*>& st){
    if(st.empty())
        return INT_MAX;
    else return st.top()->data;
}
node* constructIterative(int* preOrder, int n){

    stack<node* > st;
    int preIndex = 0;

    node* root = new node(preOrder[preIndex]);
    preIndex++;

    node* curr = root;
    while(preIndex<=n){

        // If next element is less then current node, then insert on left side of current node
        if(preOrder[preIndex]<curr->data){
            node* temp = new node(preOrder[preIndex++]); // move preIndex ahead
            curr->lchild = temp;
            st.push(curr); // because we'll later need the node for insertion on right side
            curr = temp;   // move current to this node
        }else{

            // If the current node occurs between the current node and parent of current node(as it happens in inorder)
            if(preOrder[preIndex]>curr->data && preOrder[preIndex]<checkStackTop(st)){
                node* temp = new node(preOrder[preIndex++]);
                curr->rchild = temp;
//                st.push(curr) // won't push into stack as we are done with this
                curr = temp;
            // If the current node is bigger than parent node itself, move the curr there
            }else{
                curr = st.top();
                st.pop();
            }
        }
    }
    return root;
}

//-----------------------------------------------------------------------------------

int main(){

//    node* root = test_input();
//    node* temp = isearch_bst(root, 30);

//    node* root = new node(30);
//    root = iinsert_bst(root, 20);
//    root = iinsert_bst(root, 40);
//    root = iinsert_bst(root, 10);
//    root = iinsert_bst(root, 25);
//    root = iinsert_bst(root, 35);
//    root = iinsert_bst(root, 50);

    int preOrder[] = {30, 20, 10, 25, 40, 35, 50};
    node* root = constructIterative(preOrder, (sizeof(preOrder)/sizeof(preOrder[0]))-1);
    root = deleteNode(root, 30);
    inOrder(root); cout<<endl;
    cout<<isBST2(root)<<endl;


return 0;
}
