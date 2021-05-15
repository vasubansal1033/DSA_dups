class Solution {
public:
    int minOperations(int n) {

        ios_base::sync_with_stdio(0); cin.tie(0);

        return n*n/4;
//         unsigned int sum = 0;

//         if(!(n&1)){
//             for(int i=n-1; i>=ceil(n/2); i--) sum+=(2*i+1);
//         }else{
//             for(int i=n-1; i>(n/2); i--) sum+=(2*i+1);
//         }

//         for(int i=0; i<n/2; i++) sum-=(2*i+1);

//         return sum/2;
    }
};
