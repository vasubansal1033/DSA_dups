class ProductOfNumbers {
public:
    vector<int> myList;
    ProductOfNumbers() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        myList = {1};
    }

    void add(int num) {
        if(num==0){
            myList = {1};
        }else{
            myList.push_back(myList[myList.size()-1]*num);
        }
    }

    int getProduct(int k) {

        if(k>=myList.size()) return 0;
        return myList[myList.size()-1]/myList[myList.size()-1-k];

    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
