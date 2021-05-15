#include<iostream>
using namespace std;

void fun(int x){

    if(x>0){

        fun(x-1);
        cout<<x<<" ";

    }

}
int main(){

    fun(5);

return 0;
}
