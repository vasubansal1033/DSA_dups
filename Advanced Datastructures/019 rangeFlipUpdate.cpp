#include<bits/stdc++.h>
using namespace std;

int countWays(int mask, int n, int cnt){

    if(mask == pow(2, n)-1){
        return cnt;
    }
    for(int i=0; i<n; i++){

        for(int j=i; j<n; j++){

            int temp = mask;
            for(int k=i; k<=j; k++){

                if(temp & (1<<k)) temp = temp ^ (1<<k);
                else temp = temp | (1<<k);

            }
            return countWays(temp, n, cnt+1);

        }

    }

    return -1;

}
int ans(string& str){

    int mask = stoi(str, 0, 2);
    cout<<mask;
    int n = str.size();

    return countWays(mask, n, 0);

}
int main(){

    string str = "0110";
//    cin>>str;

    cout<<ans(str);

return 0;
}
