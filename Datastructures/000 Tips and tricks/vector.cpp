#include<bits/stdc++.h>
using namespace std;


void modify(const vector<int > &v){ // passing by reference saves time
                                    // no copy is created
//    v[0]++; // can't change vector as const is passed
}
int main(){

    // Vectors
    vector<int> v(10, 5); // Initialize a vector of length 10 with all 5
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    vector<int> v1; // Empty vector
    for(int i=0; i<10; i++){
        v1.push_back(i);
    }
    for(int i=0; i<10; i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;

//    vector<int> v2[10] = {0}; //wrong
    vector<int> v2[10]; // This creates an array of empty vectors
    for(int i=0; i<10; i++){
        for(int j=0; j<=i; j++){
            v2[i].push_back(j); // v[i] is ith vector
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0 ;j<=i; j++){
            cout<<v2[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    vector<int> v3(20); // vector of size 20
    for(int i=0;i<20;i++){
        v3[i] = i+1;
    }
    v3.resize(25); // vector resized to 25

    for(int i=20; i<25;i++){
//        v3[i] = i*2;
        v3.push_back(i*2); // appends at the end of vector
                            // that is after 25 elements
    }
    cout<< v3.size()<<endl; // vector size is 30
    v3.clear(); // clears vector
    cout<<v3.size()<<endl;

    cout<<endl;

    // creating a matrix using vectors
    // Creates an m by n matrix containing all ones
    int m(10), n(5);
    vector<vector<int> > matrix(m, vector<int>(n, -1));
    cout<<matrix.size()<<endl;
    cout<<matrix[0].size()<<endl;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<< matrix[i][j]<<" ";
        }
        cout<<endl;
    }

return 0;
}
