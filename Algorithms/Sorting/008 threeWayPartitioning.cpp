#include<bits/stdc++.h>
using namespace std;


void threeWayPartitioningUtil(vector<int>& v, int start, int last){

    if(start>=last)
        return;

    int pivot = v[start]; // first element is pivot
    int lt(start), gt(last);

    // elements to the left of lt will be less than pivot
    // elements to the right of gt will be greater than pivot
    // elements b/w lt and gt both inclusive are equal to pivot

    {
        int i = start;
        while(i<=gt){

            if(v[i]<pivot){
                swap(v[i], v[lt]);
                i++;
                lt++;
            }
            else if(v[i]>pivot){
                swap(v[i], v[gt]);
                gt--;
            }else{
                i++;
            }

        }
    }

// for sorting the arrays
//    threeWayPartitioningUtil(v, start, lt-1);
//    threeWayPartitioningUtil(v, gt+1, last);

}
void threeWayPartitioning(vector<int>& v){
    threeWayPartitioningUtil(v, 0, v.size()-1);
}
int main(){

    vector<int> v = {1, 4, 2, 4, 2, 4, 1, 2, 4, 1, 2, 2, 2, 2, 4, 1, 4, 4, 4};
    threeWayPartitioning(v);
    for(auto i:v)
        cout<<i<<" ";

    return 0;

}
