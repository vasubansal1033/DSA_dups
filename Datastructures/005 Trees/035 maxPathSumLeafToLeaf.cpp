/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
int util(Node* root, int& res){

    // base case
    if(root==nullptr) return 0;
    if((root->left)==nullptr && (root->right)==nullptr) return root->data;

    if(root->right==nullptr){
        int leftAns = util(root->left, res);

        return leftAns+(root->data);
    }
    if(root->left==nullptr){
        int rightAns = util(root->right, res);

        return rightAns+(root->data);
    }

    // calculate left and right answers
    int leftAns = util(root->left, res);
    int rightAns = util(root->right, res);

    res = max(res, leftAns+(root->data)+rightAns);

    return max(leftAns, rightAns)+(root->data);

}
int maxPathSum(Node* root)
{
    // code here
    int res = INT_MIN;
    int res_ = util(root, res);

    return res;
}
