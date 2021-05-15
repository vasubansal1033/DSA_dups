vector<int> pancakeSort(vector<int>& A) {

    // first find maximum element
    // reverse s.t. it gets at first place
    // again reverse so that its at last place
    int j(0);
    vector<int> res;
    while(j<A.size()-1){

        // find max element, reverse till that index, so that it's at first place
        auto maxEleIterator = max_element(A.begin(), A.end()-j);
        reverse(A.begin(), maxEleIterator+1); // second iterator not included
        res.push_back(maxEleIterator+1-A.begin());

        // now reverse s.t. it gets placed at end
        reverse(A.begin(), A.end()-j);
        res.push_back(A.end()-j-A.begin());

        j++; // at each iteration, last element gets placed correctly
        // so increment j s.t. A.end()-j moves backward
    }

    return res;

}
