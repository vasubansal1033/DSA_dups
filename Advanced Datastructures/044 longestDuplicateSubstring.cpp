#define N 100005
class Solution{
public:
    int sz, gap;
    int suffixArray[N], pos[N], temp[N], lcp[N];

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
            suffixArray[i] = i, pos[suffixArray[i]] = str[i];        }

        gap = 0;
        sort(suffixArray, suffixArray+sz, [&](int i, int j){
            return suffixComparison(i, j);
        });
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
    void buildLCP(string& str){

        // compare the substring at index i, and at index pos[i]+1.
        // check each characters, and count the number of same characters.
        // break if there's different character
        for (int i=0, k = 0; i<sz; ++i){

            if(pos[i]!= sz - 1){
                for(int j=suffixArray[pos[i]+1]; str[i+k]==str[j+k];) ++k;

                // LCP of the position i now have the count of same characters
                lcp[pos[i]] = k;
                if(k) k--;
            }

        }

    }

    string longestDupSubstring(string& S) {

        ios_base::sync_with_stdio(0);
        cin.tie(0);

        if(S.size()==0) return "";
        sz = S.size();
        buildSA(S); buildLCP(S);

        int len = 0,start = 0;
        for(int i=0;i<N;i++){
            if(len<lcp[i]){
                len  = lcp[i]; start = suffixArray[i];
            }
        }
        return S.substr(start,len);
	}

};
