#include<bits/stdc++.h>
using namespace std;

//int lcs(string str1, string str2, int a, int b){
//
//    if(a==0||b==0)
//        return 0;
//
//    if(str1[a-1]==str2[b-1])
//        return 1+lcs(str1, str2, a-1, b-1);
//    return max(lcs(str1, str2, a-1, b),
//               lcs(str1, str2, a, b-1));
//
//}

int dplcs(string str1, string str2, int a, int b){

    int arr[a+1][b+1];
    for(int i=0; i<=b; i++){
        arr[0][i]=0;
    }
    for(int i=1; i<=a; i++){
        arr[i][0] = 0;
    }

    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){

            if(str1[i-1]==str2[j-1])
                arr[i][j] = 1+arr[i-1][j-1];
            else
                arr[i][j] = max(arr[i-1][j],
                                arr[i][j-1]);

        }
    }
    return arr[a][b];

}
int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){
        string str1, str2;
        int a, b; cin>>a>>b;
        cin>>str1>>str2;
        cout<<dplcs(str1, str2, a, b)<<endl;
    }

return 0;
}
