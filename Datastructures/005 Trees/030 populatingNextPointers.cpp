/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {

        if(!root) return root;

        if(root->left)
            root->left->next = root->right;

        if(root->next && root->right)
            root->right->next = root->next->left;

        Node* lchild = connect(root->left);
        Node* rchild = connect(root->right);

        return root;

    }
};



/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {

        if(!root) return root;

        Node* curr = root;
        queue<Node*> q;
        q.push(curr);
        while(!q.empty()){

            int sz = q.size();
            for(int i=0; i<sz; i++){


                Node* front = q.front(); q.pop();

                front->next = i!=sz-1?q.front():nullptr;

                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);


            }

        }

        return root;

    }
};
