class Solution {
public:
    int countOrders(int n) {

        vector<int> arr(n+1);
        arr[1] = 1;
        for(int i=2; i<=n; i++){
            // number of gaps |*|*|*|*| -> 2*2+1 = 5
            // no of ways of choosing is nC1 + nC2
            int n = 2*(i-1)+1;
            long long int temp = (n+n*(n-1)/2)%(1000000000+7);
            long long int temp2 = (temp*arr[i-1])%(1000000000+7);
            arr[i] = temp2;
        }

        return arr[n];

    }
};
