#include<iostream>
using namespace std;

class outer{

public:
    int a = 10;
    static int b;

    void fun(){
        i.show();
        cout<<i.x<<endl; // Outer class can only access public member of inner class
    }

    class inner{
        public:
            int x = 50;
            void show(){
//                cout<<a;
                cout<<b<<endl; // Inner class can only access the static members of the outer class
            }

        protected:
            int y;
        private:
            int z;
    };
    inner i;
};
int outer::b = 20;
int main(){

    outer object1;
    object1.fun();

return 0;
}
