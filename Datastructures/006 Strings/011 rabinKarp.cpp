class Solution {
public:
    int strStr(string haystack, string needle) {

        // base cases
        if(needle.size()==0) return 0;
        if(haystack.size()==0) return -1;
        if(needle.size()==haystack.size())
            return haystack==needle?0:-1;
        if(needle.size()>haystack.size()) return -1;

        long long int hashP(0), hashT(0);
        long long int prime = 101;
        long long int mod = pow(10, 9)+7;

        long long int d = 1;
        for(int i=0; i<needle.size(); i++){

            hashP = ((hashP*prime)%mod+needle[i]%mod)%mod;
            hashT = ((hashT*prime)%mod+haystack[i]%mod)%mod;
            if(i>0)
                d = (d*prime)%mod;
        }

        for(int i=0; i<haystack.size()-needle.size()+1; i++){
            // cout<<hashP<<" "<<hashT<<'\n';
            if(hashP==hashT){

                // for(int j=0; j<needle.size(); j++)
                //     if(haystack[j+i]!=needle[j])
                //         break;
                return i;

            }else{
                // hashT = (((mod+hashT-d*haystack[i])))%mod;
                int a = hashT%mod;
                int b = ((d%mod)*(haystack[i]%mod))%mod;
                hashT = (mod+a-b)%mod;
                hashT = ((hashT*prime)%mod+haystack[i+needle.size()])%mod;
            }

        }
        return -1;

    }
};
