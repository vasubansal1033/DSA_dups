#define N 500005
class Solution {
public:
    int sz, gap;
    int suffixArray[N], pos[N], temp[N]; //lcp[N];
    // int* suffixArray, pos, temp, lcp;

    // compare the position (char val) of each substrings, at the position i and j.
    bool suffixComparison(int i, int j){

        // sort as 'a' to 'z'
        if (pos[i] != pos[j]) return pos[i]<pos[j];
        i+= gap; j+= gap;

        // let bigger SA index comes first as that substring is shorter.
        return (i<sz && j<sz)?(pos[i]<pos[j]):(i>j);
    }
    void buildSA(string& str){

        sz = str.size();
        for(int i=0; i<sz; i++){
            suffixArray[i] = i, pos[i] = str[i];
        }

        for(gap=1;; gap *= 2){

            sort(suffixArray, suffixArray+sz, [&](int i, int j){
                return suffixComparison(i, j);
            });
            //   increase the next item if, the position(char val) of the next SA index is bigger.
            for(int i=0; i<sz-1; i++)
                temp[i+1] = temp[i]+suffixComparison(suffixArray[i], suffixArray[i + 1]);
            // by changing the 'pos' and sorting again
            // we can properly sort the SA array in Alphabetic and length based way.
            for(int i=0; i<sz; i++)
                pos[suffixArray[i]] = temp[i];
            if (temp[sz-1] == sz-1) break;
        }
    }
    // void buildLCP(){
    //     for (int i=0, k = 0; i<sz; ++i)
    //         if(pos[i]!= sz - 1){
    //             for(int j=suffixArray[pos[i]+1]; str[i+k]==str[j+k];) ++k;
    //             lcp[pos[i]] = k;
    //             if(k) k--;
    //     }
    // }
    string lastSubstring(string& str){
        ios_base::sync_with_stdio(0); cin.tie(0);
        buildSA(str);
        return str.substr(suffixArray[str.size()-1]);
    }
};
