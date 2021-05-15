typedef long long int lli;

class Solution {
public:

    void fractionToDecimalUtil(lli n, lli d, string& res){

        unordered_map<lli, lli> hashmap;

        while(n!=0){

            n = n*10;
            while(n<d){
                res += "0";
                n = n*10;
            }

            // current numerator is present
            // means fraction will repeat from here
            if(hashmap.find(n)!=hashmap.end())
                break;

            res += to_string(n/d); // n/d is integer

            hashmap[n] = res.size(); // store the numerator with size, so that we can return

            n = n%d;

        }

        // terminating decimal
        if(n==0)
            return;

        string prefix = res.substr(0, hashmap[n]-1);
        string suffix = res.substr(hashmap[n]-1, res.size()-hashmap[n]+1);

        // cout<<res;
        res = prefix + "(" + suffix + ")";


    }
    string fractionToDecimal(int numerator, int denominator) {

        // lli makes sense for these
        // in the case of n = INT_MIN, d = 1
        lli n(numerator), d(denominator);

        if(n==0)
            return "0";

        string res = "";

        // this can cause integer overflow
        // if(n*d<0){
        //     res += "-";
        // }
        if(d*n<0)
            res += "-";


        n = abs(n);
        d = abs(d);

        res += to_string(n/d); // add the number before decimal
        n = n%d;

        if(n==0)
            return res;

        res += ".";

        fractionToDecimalUtil(n, d, res);

        return res;



    }
};
