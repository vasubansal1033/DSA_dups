class Solution {
public:
    long long ncr(int n, int r){

        if(n<r) return -1;

        r = min(r, n-r);
        if(r==0) return 1;
        if(r==1) return n;

        long long p = 1, q = 1;
        while(r){

            p*= 1LL*n;
            q*= 1LL*r;

            long long m = __gcd(p, q);
            p = p/m;
            q = q/m;

            n--; r--;
        }

        return p;

    }
    string kthSmallestPath(vector<int>& destination, int k) {

        ios_base::sync_with_stdio(0); cin.tie(0);

        string res = "";

        int rows = destination[0];
        int cols = destination[1];

        int remDown = rows;
        int remRight = cols;

        for(int i=0; i<rows+cols; i++){

            int remSteps = rows+cols-(i+1);
            int nCr = ncr(remSteps, remDown);

            if(nCr>=k){
                res.push_back('H');
            }else{
                remDown--;
                k-=nCr;
                res.push_back('V');
            }



        }
        return res;

    }
};
