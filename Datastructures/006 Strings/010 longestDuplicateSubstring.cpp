// My solution
// look 2nd solution using string_view which is basically same solution but memory efficient
class Solution {
public:
    int prime = 7;
    int mod = pow(10, 5)+7;
    int getHash(string& s, int i, int len){

        int ans = 0;
        for(int j=0; j<len; j++){
            ans = ((ans*prime)%mod+(s[i+j]-'a'))%mod;
        }

        return ans;

    }
    string longestDupSubstring(string s) {

        // answer will lie between 1 and s
        // So binary search for the answer
        // Each time, checking will take O(n) time
        // So complexity will be O(nlogn)

        int lo(1), hi(s.size()-1);
        unordered_map<int, string> set;
        string res = "";

        while(lo<hi){

            int mid = lo+(hi-lo+1)/2;
            bool flag = true;
            set.clear();

            int d = 1;
            for(int i=0; i<mid-1; i++)
                d = (d*prime)%mod;
            for(int i=0; i<s.size()-mid+1; i++){

                int hash;
                if(i==0)
                    hash = getHash(s, i, mid);
                else
                    hash = (((mod+hash - d*(s[i-1]-'a'))*prime)%mod+(s[i+mid-1]-'a'))%mod;
                if(set.find(hash)==set.end()){
                    set[hash] = s.substr(i, mid+1);
                }

                else{

                    if(set[hash]==s.substr(i, mid+1)){
                        lo = mid;
                        flag = false;
                        res = s.substr(i, mid+1);
                        break;
                    }

                }

            }
            if(flag){
                hi = mid-1;
            }


        }
        return res;


    }
};

class Solution {
public:
   string longestDupSubstring(string str) {
    string_view ans;
    unordered_set<string_view> s;
    int l = 0;
    int h = str.size();
    int m;
    while(l<=h)
    {
        bool flag = 0;
        m = l+(h-l)/2;
        auto t = string_view(str);
        for(int i=0;i<str.size()-m+1;++i)
        {
            auto x = t;
            x.remove_prefix(i);
            x.remove_suffix(str.size()-m-i);
            auto y = s.insert(x);
            if(y.second != true)
            {
                flag = 1;
                ans = x;
                break;
            }
        }
        if(flag)
            l = m+1;
        else h = m-1;
    }
    return string(ans);
}
};
