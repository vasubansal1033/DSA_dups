vector<int> duplicates(int a[], int n) {
    // code here
    vector<int> res;

    // important technique
    // use the array itself to create a frequency hashmap
    // works when a array of size n has elements from 0 to n-1

    for(int i=0; i<n; i++){
        a[(a[i]%n)] = a[(a[i]%n)]+n;
    }
    for(int i=0; i<n; i++){
        if(a[i]/n>1)
            res.push_back(i);
    }

    if(res.empty()) return {-1};
    else return res;


}
