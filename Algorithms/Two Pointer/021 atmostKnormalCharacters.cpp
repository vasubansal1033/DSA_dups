#include<bits/stdc++.h>
using namespace std;

// find longest substring containing atmost k normal characters
int ans(string& p, string& q, int k){

    int i(0), j(0);
    int start, last;
    int normal_chars = 0;
    int res = 0;

    while(j<p.size()){

        while(j<p.size() && normal_chars<=k){

            if(q[p[j]-'a']=='0'){

                if(normal_chars==k) break;
                else normal_chars++;

            }

            j++;
            if(res<j-i && normal_chars<=k){
                start = i;
                last = j;
                res = j-i;
            }

        }

        while(i<j && normal_chars>=k){
            if(q[p[i]-'a']=='0') normal_chars--;
            i++;
        }

    }

    cout<<p.substr(start, res);
    return res;

}

int main(){

    string p = "giraffe";
    string q = "01111001111111111011111111"; //a,f,g,r

//    string p = "abcde";
//    string q = "10101111111111111111111111";
    int k = 2;

    cout<<ans(p, q, k);

return 0;
}
