#include<iostream>
using namespace std;

int max(int x, int y){
    return x>y?x:y;
}
int min(int x, int y){
    return x>y?y:x;
}

int main(){


    int a = 10;
    int *p; // Declaring a pointer
    p = &a; // Initializing pointer

    cout<<a<<endl;
    cout<<p<<endl;
    cout<<&a<<endl;
    cout<< *p <<endl; // Dereferencing pointer

//    delete p; // we can't delete p as it's not referring to a memory in heap
    // Heap memory allocation and Dynamic Memory Allocation
    int *q = new int[5];
    q[2]= 23;

    delete[] q;

    q = new int[10];

    // make pointer null after deleting the memory
    delete []q;
    q = nullptr;
    cout<<"-----------------"<<endl;


    // Pointer arithmetic
    int arr[5]={3,2,4,9,20};
    int *r=arr, *s=&arr[3];

    cout<<*r<<" "<<*s<<endl;
    r++; s--;
    cout<<*r<<" "<<*s<<endl;
    r--; s++;
    cout<<s-r<<" hello"<<endl;
    for(int j=0;j<5;j++){
        cout<<arr[j]<<" "<<j[arr]<<endl;
        cout<<*(arr+j)<<" "<<*(j+arr)<<endl;
        cout<<arr+j<<endl;
    }

    int (*fp)(int, int) = max;
    cout<<(*fp)(10,5)<<endl;
//    int (*fp)(int, int) = min;
    fp = min;
    cout<<(*fp)(10,5)<<endl;



return 0;
}
