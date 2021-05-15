#include<bits/stdc++.h>
using namespace std;

void shellSort(vector<int>& v){

    for(int gap = ceil(v.size()/2); gap>=1; gap/=2){

        for(int i = gap; i<v.size(); i++){

            int temp = v[i], j;
            for(j = i; j-gap>=0 && v[j-gap]>temp; j-=gap){
                v[j] = v[j-gap];
            }

            v[j] = temp;

        }

    }

}
int main(){

    vector<int> v = {6, 3, 26 ,2 -214, 4369, 1, 34, 547, 2235, 765, 43};
    shellSort(v);

    for(auto i:v) cout<<i<<" ";

return 0;
}
