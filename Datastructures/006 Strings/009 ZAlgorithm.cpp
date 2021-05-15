class Solution {
public:
    void z_algo(string& str, vector<int>& arr){

        int l(0), r(0);
        for(int i=1; i<str.size(); i++){

            if(i>r){

                l = r = i;
                while(r<str.size() && str[r]==str[r-l])
                    r++;
                r--;
                arr[i] = r-l+1;

            }else{

                int idx = i-l;
                if(i+arr[idx]<=r){
                    arr[i] = arr[idx];
                }else{

                    l = i;
                    while(r<str.size() && str[r]==str[r-l])
                        r++;
                    r--;
                    arr[i] = r-l+1;

                }

            }

        }

    }
    int strStr(string haystack, string needle) {

        if(needle.size()==0) return 0;
        if(haystack.size()==0) return -1;

        string z_string = needle+'#'+haystack;
        vector<int> z_array(z_string.size());

        z_algo(z_string, z_array);

        for(int i=0; i<z_array.size(); i++){
            if(z_array[i]==needle.size()){
                return i-needle.size()-1;
            }
        }

        return -1;
    }
};
