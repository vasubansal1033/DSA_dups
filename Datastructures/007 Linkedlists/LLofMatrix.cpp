#include<bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/linked-list-matrix/1
// https://www.geeksforgeeks.org/construct-a-linked-list-from-2d-matrix-iterative-approach/
int MAX=300;
class Node{
public:
    int data;
    Node* right = nullptr;
    Node* down = nullptr;

    Node(int data){
        this->data=data;
    }
};
Node* constructLinkedMatrix(int mat[300][300], int n){
    // code here
   Node** matp = new Node*[MAX];
   for(int i=0;i<n;i++){
        //matp[i] = new Node[MAX]; Never use new Node[] as it is clashes with constructor
        matp[i] = (Node*) malloc(MAX*sizeof(Node));
       for(int j=0;j<n;j++){
           (matp[i][j]).data = mat[i][j];
           if(i-1>=0){
              (matp[i-1][j]).down = &matp[i][j];
           }
           if(j-1>=0){
               (matp[i][j-1]).right = &matp[i][j];
           }
       }

   }
   return &matp[0][0];
}
void arrInput(int** arr, int n){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    return;
}
void displayArr(int** arr, int n){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j];
        }
    }
}

int main(){

    int n;
    cin>>n;
    int** arr = new int*[n];
    arrInput(arr, n);
    displayArr(arr, n);
return 0;
}

/* ----- RECURSIVE SOLUTION -------
// creates wastefull new nodes
// create a 2d array which stores address of the corresponding element. check for it if not empty then return it

Node* construct(int mat[MAX][MAX], int n, int i, int j){

    if(i>=n || j>=n){
        return NULL;
    }
    Node* temp = new Node(mat[i][j]);
    temp->down = construct(mat,  n, i+1, j);
    temp->right = construct(mat, n, i, j+1);
    return temp;

}
Node* constructLinkedMatrix(int mat[MAX][MAX], int n)
{
    // code here
    return construct(mat, n, 0 , 0);
}

*/
