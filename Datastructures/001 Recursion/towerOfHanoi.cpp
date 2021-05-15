#include<iostream>
using namespace std;

void towerOfHanoi(int n, char A, char B, char C){

    if(n>0){
        towerOfHanoi(n-1, A, C, B);
        cout<<"Move from "<<A<<" to "<<C<<endl;
        towerOfHanoi(n-1, B, A, C);
    }

}
int main(){

    towerOfHanoi(3, 'A', 'B', 'C');

return 0;
}
