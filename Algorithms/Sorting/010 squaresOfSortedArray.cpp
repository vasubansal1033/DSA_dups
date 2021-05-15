vector<int> sortedSquares(vector<int>& A) {

    int j(0);

    vector<int > ans;

    while(j<A.size() && A[j]<0){
        j++;
    }
    if(j==A.size()){
        for(int i=A.size()-1; i>=0; i--)
            ans.push_back(A[i]*A[i]);
        return ans;
    }



    int i(j-1);
    while(j<A.size() && i>=0 ){

        int a(A[i]*A[i]), b(A[j]*A[j]);


        if(a<b){
            ans.push_back(a);
            i--;
        }
        if(a>b){
            ans.push_back(b);
            j++;
        }
        if(a==b){
            ans.push_back(a);
            ans.push_back(b);
            i--;
            j++;
        }

    }
    while(j<A.size()){
        ans.push_back(A[j]*A[j]);
        j++;
    }
    while(i>=0){
        ans.push_back(A[i]*A[i]);
        i--;
    }


    return ans;

}
