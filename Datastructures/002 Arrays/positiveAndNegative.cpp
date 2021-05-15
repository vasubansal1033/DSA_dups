#include<bits/stdc++.h>
using namespace std;

void swap1(int* arr, int i, int j){
    arr[i] = arr[i]+arr[j];
    arr[j] = arr[i]-arr[j];
    arr[i] = arr[i]-arr[j];
}
void fun(int* arr){

    int n = 13;
    int i=0, j=n-1;

    while(i<j){

        while(arr[i]<0){
            i++;
        }
        while(arr[j]>=0){
            j--;
        }
        if(i<j){
            swap1(arr, i, j);

        }
    }
}
int main(){

    int* arr = new int[13];
    int arr1[] = {4, -5, 0, 12, -3, 39, 45, -34, -9, -998, 23, 24,-35};

    for(int i=0;i<13;i++){
        arr[i]=arr1[i];
    }
    cout<<endl;
    fun(arr);

//    int s = sizeof(arr);
    for(int i=0-0;i<13;i++){
        cout<<arr[i]<<" ";
    }

return 0;
}
